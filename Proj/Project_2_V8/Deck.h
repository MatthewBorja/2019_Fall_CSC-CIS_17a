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
        unsigned char nCards;    //Number of cards.
        unsigned char nShuffle;  //Number to shuffle.
        unsigned char nDealt;    //Number dealt.
        unsigned char *indx;     //Char pointer.
        Card **card;    //Card double pointer "card".
    public:
        Deck(unsigned char);         //Constructor
        ~Deck();            //Destructor
        void shuffle();     //Shuffle function
        unsigned char *deal(unsigned char);   //Deal function
        void display();
};

#endif /* DECK_H */