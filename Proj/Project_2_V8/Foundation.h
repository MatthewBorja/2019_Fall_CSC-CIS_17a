/* File:   Foundations.h
 * Author: Matthew Borja
 * Created on December 4, 2019, 11:16 PM
 * Purpose: The specification for the Foundation class.
 */

#ifndef FOUNDATION_H
#define FOUNDATION_H

#include <iostream>
#include "Deck.h"
#include "Pile.h"
using namespace std;

class Foundation{
    private:
        bool cFull;
        bool dFull;
        bool hFull;
        bool sFull;
        bool won;
        unsigned char *c;
        unsigned char *d;
        unsigned char *h;
        unsigned char *s;
        int numOfCCrds;
        int numOfDCrds;
        int numOfHCrds;
        int numOfSCrds;
        friend class Player;
    public:
        Foundation();               //Default constructor.
        bool addToC(unsigned char);     //Functions for adding
        bool addToD(unsigned char);     //new cards to the
        bool addToH(unsigned char);     //foundations.
        bool addToS(unsigned char);
        void display() const;       //Display foundations each turn.
        bool legalCheckC(Card);     //Is the added card a legal move?
        bool legalCheckD(Card);
        bool legalCheckH(Card);
        bool legalCheckS(Card);
        bool complete();
        bool victory();
};

#endif /* FOUNDATION_H */

