/* File:   Table.h
 * Author: Matthew Borja
 * Created on December 6, 2019, 12:26 PM
 * Purpose: The specification of Table class.
 */

#ifndef TABLE_H
#define TABLE_H
#include "Deck.h"
#include "Pile.h"
#include "Foundation.h"

const int NUMPILES=7;   //A game of solitaire has 7 piles of cards in the center.

class Table{
    private:
        int pileNum;
        int maxPerPile;
        char *tableau;
        Foundation fndtion;
        Pile *stock;
    public:
        Table();
        ~Table();
        setTableau(char *);
        setFoundation();
        //Display();
        
};

#endif /* TABLE_H */

