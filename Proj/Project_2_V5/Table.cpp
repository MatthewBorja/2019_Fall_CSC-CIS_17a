/* 
 * File:   Table.cpp
 * Author: Matthew Borja
 * Created on December 6, 2019, 12:33 PM
 * Purpose: The implementation of Table class.
 */

#include "Table.h"

Table::Table(){
    maxPerPile=7;
    pileNum=0;
    tableau=new char[NUMPILES];
    stock=nullptr;
}

Table::~Table(){
    delete []tableau;
}

Table::setTableau(char *pile){
    tableau[pileNum]=*pile;
    pileNum++;
}

Table::setFoundation(){
    
}