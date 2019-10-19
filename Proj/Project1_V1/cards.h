/* File:   cards.h
 * Author: Matthew Borja
 * Created on October 16, 2019, 12:01 PM
 * Purpose: Create a structure to represent cards.
 */

#ifndef CARDS_H
#define CARDS_H

struct Card{
    char side = 'X';   //Initialized face down.
    char suit;
    int value;
};

enum Suits {CLUBS='C',DIAMONDS='D',HEARTS='H',SPADES='S'};
enum Ranks {JACK=10, QUEEN=11, KING=12};
const int NUM_SUITS=4;      //For use in For Loops
const int NUM_VALUES=13;    //For use in For Loops.

#endif /* CARDS_H */