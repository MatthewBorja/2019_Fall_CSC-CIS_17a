/* 
 * File:   Table.cpp
 * Author: Matthew Borja
 * Created on December 6, 2019, 12:33 PM
 * Purpose: The implementation of Table class.
 */

#include "Table.h"

Table::Table(){

}

Table::~Table(){
    for(char crd=0;crd<maxPerPile;crd++){
        //delete tableau[crd];
    }
    delete []tableau;
}

Table::setTableau(char *pile){
    tableau=pile;
}