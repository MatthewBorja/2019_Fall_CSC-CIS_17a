/* File:   Table.h
 * Author: Matthew Borja
 * Created on December 6, 2019, 12:26 PM
 * Purpose: The specification of Table class.
 */

#ifndef TABLE_H
#define TABLE_H
#include "Pile.h"
#include "Foundation.h"

class Table{
    private:
        int maxPerPile=7;
        char *tableau;
        Foundation fndtion;
        Pile *stock;
    public:
        Table();
        ~Table();
        setTableau(char *);
        //Display();
        
};

#endif /* TABLE_H */

