/* File:   Pile.h
 * Author: Matthew Borja
 * Created on December 5, 2019, 11:51 AM
 * Purpose: The specification of Pile class. Represent a pile of cards besides
 *          Hand. I.E. the Stock pile, the Waste pile...
 */

#ifndef PILE_H
#define PILE_H

#include <iostream>

class Pile{
    private:
        unsigned char nCards;
        unsigned char *cards;
    public:
        Pile();
        Pile(unsigned char *,unsigned char);
        ~Pile();
        void display();
};

#endif /* PILE_H */

