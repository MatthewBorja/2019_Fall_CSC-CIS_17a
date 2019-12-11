/* 
 * File:   Foundation.cpp
 * Author: Matthew Borja
 * Created on December 5, 2019, 12:03 PM
 * Purpose: The implementation of the Foundation class.
 */

#include "Foundation.h"

Foundation::Foundation(){
    c=nullptr;
    d=nullptr;
    h=nullptr;
    s=nullptr;
    numOfCCrds=0;
    numOfDCrds=0;
    numOfHCrds=0;
    numOfSCrds=0;
}

void Foundation::display() const{
    int count;
    for(count=0;count<numOfCCrds;count++){
        Card cCrd(c[count]);
        cout<<cCrd.face()<<cCrd.suit()<<" "<<static_cast<int>(cCrd.value())<<", ";
    }
    cout<<"."<<endl;
    for(count=0;count<numOfDCrds;count++){
        Card dCrd(d[count]);
        cout<<dCrd.face()<<dCrd.suit()<<" "<<static_cast<int>(dCrd.value())<<", ";
    }
    cout<<"."<<endl;
    for(count=0;count<numOfHCrds;count++){
        Card hCrd(h[numOfHCrds]);
        cout<<hCrd.face()<<hCrd.suit()<<" "<<static_cast<int>(hCrd.value())<<", ";
    }
    cout<<"."<<endl;
    for(count=0;count<numOfHCrds;count++){
        Card sCrd(s[numOfSCrds]);
        cout<<sCrd.face()<<sCrd.suit()<<" "<<static_cast<int>(sCrd.value())<<", ";
    }
    cout<<"."<<endl;
}

void Foundation::addToC(char*crd,int crdNum){
    Card candidate(crd[crdNum]);
    if(legalCheckC(candidate)){
        
    }
    else{
        cout<<"Invalid move."<<endl;
    }
}

void Foundation::addToD(char*crd,int crdNum){
    Card candidate(crd[crdNum]);
    if(legalCheckD(candidate)){
        
    }
    else{
        cout<<"Invalid move."<<endl;
    }
}

void Foundation::addToH(char*crd,int crdNum){
    Card candidate(crd[crdNum]);
    if(legalCheckH(candidate)){
        
    }
    else{
        cout<<"Invalid move."<<endl;
    }
}

void Foundation::addToS(char*crd,int crdNum){
    Card candidate(crd[crdNum]);
    if(legalCheckS(candidate)){
        
    }
    else{
        cout<<"Invalid move."<<endl;
    }
}

bool Foundation::legalCheckC(Card crd){
    
}

bool Foundation::legalCheckD(Card crd){
    
}

bool Foundation::legalCheckH(Card crd){
    
}

bool Foundation::legalCheckS(Card crd){
    
}