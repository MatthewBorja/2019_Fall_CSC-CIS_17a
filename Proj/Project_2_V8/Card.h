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
        unsigned char cNum;   //Private data member
    public:
        Card(unsigned char);  //Constructor
        //Member functions to...
        unsigned char suit(); //... get suits,
        unsigned char face(); //... get faces,
        unsigned char value();//... get values.
};

#endif /* CARD_H */