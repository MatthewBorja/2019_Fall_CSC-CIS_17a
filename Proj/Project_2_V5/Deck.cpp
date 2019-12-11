/* 
 * File:   Deck.h
 * Author: Matthew Borja
 * Created on December 3, 2019, 1:25 PM
 * Purpose: The implementation for the Deck class. Inspired by in-class lecture.
 */

#include "Deck.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

Deck::Deck(char num){
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Initialize the card properties
    nCards=num>0?num:52;  //Conditional Operator/Ternary Operator. Short and sweet.
    nShuffle=7;           //Optimal amount of times to sufficiently shuffle 52 cards.
    nDealt=0;             //Initialize nDealt to 0. None dealt yet.
    indx=new char[nCards];  //Set indx = Dynamically allocate 52 new char pointers.
    //Dynamically allocate a Card pointer to an array of 52 new cards.
    card=new Card*[nCards]; //This is our deck.
    for(char crd=0;crd<nCards;crd++){
        //Fill our deck with card values by calling the Card constructor 52 times.
        card[crd]=new Card(crd);
        //Copy each card number to our index to manipulate the deck without altering
        //the deck.
        indx[crd]=crd;
    }
}

Deck::~Deck(){ //Destructor
    delete []indx;  //First we delete our index. Single pointer.
    //For loop to step through the Card double pointer.
    for(char crd=0;crd<nCards;crd++){
        delete card[crd];   //Delete each (new'ed) card object.
    }
    delete []card;  //Afterwards, we can delete the array.
}

void Deck::shuffle(){
    for(int x=1;x<=nShuffle;x++){
        for(int y=0;y<nShuffle;y++){
            //Assign tmpRnd a random number modulus by 52 to stay in-bounds.
            char tmpRnd=rand()%nCards;
            //Declare a new char to hold original element number.
            char temp=indx[y];
            //Swap the original element with the random number and vice versa.
            indx[y]=indx[tmpRnd];
            indx[tmpRnd]=temp;
        }
    }
}

char *Deck::deal(char nDeal){
    shuffle();
    nDealt=0;
    char *pile=new char[nDeal];
    for(char i=0;i<nDeal;i++){
        pile[i]=indx[nDealt++];
    }
    return pile;
}

//void Deck::display();