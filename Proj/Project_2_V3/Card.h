/* 
 * File:   Card.h
 * Author: Matthew Borja
 * Created on December 3, 2019, 12:45 PM
 * Purpose: The specification for the Card class.
 */

#ifndef CARD_H
#define CARD_H

class Card{
    private:
        int cNum;   //Private data member
    public:
        Card(int);  //Constructor
        //Member functions to...
        int suit(); //... get suits,
        int face(); //... get faces,
        int value();//... get values.
};

#endif /* CARD_H */