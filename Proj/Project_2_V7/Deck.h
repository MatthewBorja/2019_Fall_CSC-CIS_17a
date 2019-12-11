/* 
 * File:   Deck.h
 * Author: Matthew Borja
 * Created on December 3, 2019, 1:17 PM
 * Purpose: The specification for the Deck class. Inspired by in-class lecture.
 */

#ifndef DECK_H
#define DECK_H

#include "Card.h"   //Include our Card class.

class Deck{
    private:
        char nCards;    //Number of cards.
        char nShuffle;  //Number to shuffle.
        char nDealt;    //Number dealt.
        char *indx;     //Char pointer.
        Card **card;    //Card double pointer "card".
    public:
        Deck(char);         //Constructor
        ~Deck();            //Destructor
        void shuffle();     //Shuffle function
        char *deal(char);   //Deal function
        void display();
};

#endif /* DECK_H */