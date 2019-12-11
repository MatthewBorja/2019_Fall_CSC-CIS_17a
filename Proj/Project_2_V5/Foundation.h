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
        char *c;
        char *d;
        char *h;
        char *s;
        int numOfCCrds;
        int numOfDCrds;
        int numOfHCrds;
        int numOfSCrds;
    public:
        Foundation();           //Default constructor.
        void addToC(char*,int);          //Functions for adding
        void addToD(char*,int);          //new cards to the
        void addToH(char*,int);          //foundations.
        void addToS(char*,int);
        void display() const;   //Display foundations each turn.
        bool legalCheckC(Card);     //Is the added card a legal move?
        bool legalCheckD(Card);
        bool legalCheckH(Card);
        bool legalCheckS(Card);
};

#endif /* FOUNDATION_H */

