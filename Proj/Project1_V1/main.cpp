/* File:   main.cpp
 * Author: Matthew Borja
 * Created on October 15, 2019, 2:31 PM
 * Purpose: Simulate the game of Concentration.
 */


//System Libraries
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//User Libraries
#include "cards.h"
//Global Constants

//Function Prototypes
int menu();
void rules();
void genDeck(Card *, const int);
void sflDeck(Card *,const int);
void game(Card *,const int);
void dealCards(Card *,int,int,int);
void choice(Card *);
bool cmpCards(Card *,int,int);
void rmvCards(Card *,int,int);
void dspCards(Card *,int,int,int);
void destroy(Card *);

//Execution Begins Here
int main() {
    //Set random number seed here
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables
    const int DECKSIZE=52;
    int mnuChce;
    
    Card *deckPtr = new Card[DECKSIZE];   //Dynamically allocate a Card structure the size of a card deck.
    //Initialize Variables
    mnuChce=0;
    //Process inputs to outputs/map
    mnuChce=menu();
    if(mnuChce==1){
        cout<<"\nInitializing a new game!\n";
        genDeck(deckPtr, DECKSIZE);
        game(deckPtr, DECKSIZE);
    }
    
    //Display results
    
    //Clean up and exit stage right
    destroy(deckPtr);
    return 0;
}

int menu(){
    int input;
    cout<<"Concentration\n";
    cout<<"Made by Matthew Borja\tCIS-17A\tFall 2019\n";
    cout<<setw(20)<<"1. New Game\n";   //Option 1
    cout<<setw(17)<<"2. Rules\n";      //Option 2
    cout<<setw(16)<<"3. Exit\n";       //Option 3
    cin>>input;
        if(input==1)        //Picked New Game.
            return input;   //Return choice to main.
        if(input==2){       //Picked Rules.
            rules();        //Call rules function.
            menu();         //Reiterate menu options to user.
        }
        if(input==3)        //Picked Exit.
            exit(0);        //Exit program.
}

void rules(){
    ofstream rules;
    
    cout<<"Fetching rules...";
    rules.open("Rules.txt", ios::out);                                     //Open for output.
    rules<<"For official game rules, please visit:\n";                     //Save space and
    rules<<"https://www.classicgamesandpuzzles.com/Concentration.html";    //redirect to website.
    rules.close();                                                         //Close file.
    cout<<"Rules.txt was successfully created!\n";                         //Inform user.
}

void genDeck(Card *deckPtr, const int DECKSIZE){
    int cardNum = 0;    //Keep track of cards 0-51
    
    cout<<"Generating deck...\n";
    
    for(int suit=0; suit<NUM_SUITS; suit++){    //Step through 4 suits
        for(int val=0; val<NUM_VALUES; val++){  //Step through 13 values
            if(cardNum<=12){
                deckPtr[cardNum].suit='C';  //Clubs
            }
            else if(cardNum<=25){
                deckPtr[cardNum].suit='D';  //Diamonds
            }
            else if(cardNum<=38){
                deckPtr[cardNum].suit='H';  //Hearts
            }
            else if(cardNum<=51){
                deckPtr[cardNum].suit='S';  //Spades
            }
            deckPtr[cardNum].value=val;     //Values 0(ace)-12(King)
            cardNum++;
        }
    }
    sflDeck(deckPtr, DECKSIZE);
}

void sflDeck(Card *deckPtr, const int DECKSIZE){
    int cardOne=0, cardTwo=0, cardNum=0,counter=0, row=0, col=0;
    string myDeck[4][13];
    
    cout<<"Shuffling deck...\n";
    while(cardNum<DECKSIZE){
        cardOne=rand()%51;
        cardTwo=rand()%51;
        swap(deckPtr[cardOne],deckPtr[cardTwo]);
        cardNum++;
    }
}

void game(Card *deckPtr, const int DECKSIZE){
    int suit, rank, card=0;
    bool solved=0;
    
    cout<<"\nCONCENTRATION\n";
    dealCards(deckPtr, suit, rank, card);
    choice(deckPtr);
    do{
        dspCards(deckPtr, suit, rank, card);
        choice(deckPtr);
    }
    while(solved!=true);
    
}

void dealCards(Card *deckPtr, int suit, int rank, int card){
    for(suit=0;suit<NUM_SUITS; suit++){
        for(rank=0; rank<NUM_VALUES; rank++){
            cout<<setw(3)<<deckPtr[card].side;
            card++;
        }
        cout<<endl;
    }
}

void choice(Card *deckPtr){
    int x,y;
    bool same;
    cout<<"Pick the first card.";
    cin>>x;
    cout<<"Pick the second card to compare.";
    cin>>y;
    same=cmpCards(deckPtr,x,y);
    if(same=true){
        rmvCards(deckPtr, x, y);
    }
}

bool cmpCards(Card *deckPtr, int x, int y){
    Suits suitOne, suitTwo;
    suitOne=static_cast<Suits>(deckPtr[x].suit);
    suitTwo=static_cast<Suits>(deckPtr[y].suit);
    if (deckPtr[x].value == deckPtr[y].value){
        if (suitOne==CLUBS&&suitTwo==SPADES){
            return true;
        }
        else if (suitOne==SPADES&&suitTwo==CLUBS){
            return true;
        }
        else if (suitOne==DIAMONDS&&suitTwo==HEARTS){
            return true;
        }
        else if (suitOne==HEARTS&&suitTwo==DIAMONDS){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

void rmvCards(Card *deckPtr,int x,int y){
    deckPtr[x].side='U';
    deckPtr[y].side='U';
}

void dspCards(Card *deckPtr, int suit, int rank, int card){
    for(suit=0;suit<NUM_SUITS; suit++){
        for(rank=0; rank<NUM_VALUES; rank++){
            if(deckPtr[card].side='X'){
                cout<<setw(3)<<deckPtr[card].side;
                card++;
            }
            else if(deckPtr[card].side='U'){
                cout<<setw(3)<<deckPtr[card].suit<<deckPtr[card].value;
                card++;
            }
        }
        cout<<endl;
    }
}

void destroy(Card *deckPtr){
    delete []deckPtr;
}