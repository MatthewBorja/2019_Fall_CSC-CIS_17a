/* File:   main.cpp
 * Author: Matthew Borja
 * Created on October 15, 2019, 2:31 PM
 * Purpose: Simulate the game of Concentration.
 */


//System Libraries
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

#include "cards.h"
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int menu();
void rules();
void genDeck(Card *);
void destroy(Card *,const int);

//Execution Begins Here
int main() {
    //Set random number seed here
    
    //Declare Variables
    const int DECKSIZE=52;
    int mnuChce;
    Card *deckPtr = new Card[DECKSIZE];   //Dynamically allocate a Card structure the size of a card deck.
    //Initialize Variables
    mnuChce=0;
    //Process inputs to outputs/map
    mnuChce=menu();
    if(mnuChce==1){
        genDeck(deckPtr);
    }
    destroy(deckPtr, DECKSIZE);
    //Display results
    
    //Clean up and exit stage right
    return 0;
}

int menu(){
    int input;
    cout<<"Concentration\n";
    cout<<"Made by Matthew Borja\tCIS-17A\tFall 2019\n";
    cout<<setw(20)<<"1. New Game\n";         //Option 1
    cout<<setw(17)<<"2. Rules\n";      //Option 2
    cout<<setw(16)<<"3. Exit\n";       //Option 3
    cin>>input;
        if(input==1)         //Picked New Game.
            return input;   //Return choice to main.
        if(input==2){    //Picked Rules.
            rules();        //Call rules function.
            menu();         //Reiterate menu options to user.
        }
        if(input==3)     //Picked Exit.
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

void genDeck(Card *deckPtr){
    for (int suit=0; suit<NUM_SUITS; suit++){
        for(int val=0; val<NUM_VALUES; val++){
            deckPtr[suit].suit=suit;
            deckPtr[val].value=val;
        }
    }
    cout << "Suit: "<<deckPtr[0].suit<<"\tValue: "<<deckPtr[0].value<<endl;
    cout << "Suit: "<<deckPtr[3].suit<<"\tValue: "<<deckPtr[3].value<<endl;
}

void destroy(Card *deckPtr, const int DECKSIZE){
    for(int deck=0; deck<DECKSIZE; deck++){
        delete []deckPtr[deck];
    }
    delete []deckPtr;
}