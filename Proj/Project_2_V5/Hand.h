/* File:   Hand.h
 * Author: Matthew Borja
 * Created on December 3, 2019, 7:03 PM
 * Purpose: The specification of the Hand class.
 */

#ifndef HAND_H
#define HAND_H

class Hand{
    private:
        char nCards;
        char *cards;
    public:
        Hand(char *, char);
        ~Hand();
        void display();
};

#endif /* HAND_H */