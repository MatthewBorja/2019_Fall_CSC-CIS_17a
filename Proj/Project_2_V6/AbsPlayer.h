/* File:   AbsPlayer.h
 * Author: Matthew Borja
 * Created on December 3, 2019, 9:00 PM
 * Purpose: An abstract base class to demonstrate an abstract class.
 */

#ifndef ABSPLAYER_H
#define ABSPLAYER_H

#include <string>
using namespace std;

class AbsPlayer{
    public:
        //Abstract classes contain keyword "virtual" and "=0".
        //Inheritors must override these functions.
        virtual string getName() const=0;
        virtual void setTable()=0;
};

#endif /* ABSPLAYER_H */