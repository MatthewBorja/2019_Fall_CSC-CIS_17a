/* File:   cards.h
 * Author: Matthew Borja
 * Created on October 16, 2019, 12:01 PM
 * Purpose: Create a structure to represent cards.
 */

#ifndef CARDS_H
#define CARDS_H

struct Card{
    int suit;
    int value;
};

const int NUM_SUITS=4;
const int NUM_VALUES=13;

#endif /* CARDS_H */

