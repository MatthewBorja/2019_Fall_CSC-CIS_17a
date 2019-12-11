/* File:   Foundations.h
 * Author: Matthew Borja
 * Created on December 4, 2019, 11:16 PM
 * Purpose: The specification for the Foundation class.
 */

#ifndef FOUNDATION_H
#define FOUNDATION_H

#include <iostream>
#include "Pile.h"


class Foundation{
    private:
        Pile *c;
        Pile *d;
        Pile *h;
        Pile *s;
    public:
        Foundation();
        ~Foundation();
        display();
};

#endif /* FOUNDATION_H */

