/* 
 * File:   Foundation.cpp
 * Author: Matthew Borja
 * Created on December 5, 2019, 12:03 PM
 * Purpose: The implementation of the Foundation class.
 */

#include "Foundation.h"

Foundation::Foundation(){
    //Flags
    cFull=0;
    dFull=0;
    hFull=0;
    sFull=0;
    won=0;
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
    cout<<"--------------------FOUNDATIONS--------------------\n";
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
    for(count=0;count<numOfSCrds;count++){
        Card sCrd(s[numOfSCrds]);
        cout<<sCrd.face()<<sCrd.suit()<<" "<<static_cast<int>(sCrd.value())<<", ";
    }
    cout<<"."<<endl;
}

bool Foundation::addToC(char*crd,int crdNum){
    Card candidate(crd[crdNum]);    //Create a card object for suggested move.
    if(legalCheckC(candidate)){     //Send it in to see if legal move.
        c[numOfCCrds]=crd[crdNum];  //If legal, assign to foundation.
        if(numOfCCrds<12){
            numOfCCrds++;           //Increment counter.
        }
        else if(numOfCCrds==12){
            cFull=complete();
        }
        return true;                //Return true value so original function knows
    }                               //to update card's location.
    else{                           //Otherwise, inform user of invalid move.
        cout<<"Invalid move."<<endl;//Great place for try/catch blocks.
        return false;               //False so card can stay in place.
    }
}

bool Foundation::addToD(char*crd,int crdNum){
    Card candidate(crd[crdNum]);
    if(legalCheckD(candidate)){
        d[numOfDCrds]=crd[crdNum];
        if(numOfDCrds<12){
            numOfDCrds++;           //Increment counter.
        }
        else if(numOfDCrds==12){
            dFull=complete();
        }
        return true;
    }
    else{
        cout<<"Invalid move."<<endl;
        return false;
    }
}

bool Foundation::addToH(char*crd,int crdNum){
    Card candidate(crd[crdNum]);
    if(legalCheckH(candidate)){
        h[numOfHCrds]=crd[crdNum];
        if(numOfHCrds<12){
            numOfHCrds++;           //Increment counter.
        }
        else if(numOfHCrds==12){
            hFull=complete();
        }
        return true;
    }
    else{
        cout<<"Invalid move."<<endl;
        return false;
    }
}

bool Foundation::addToS(char*crd,int crdNum){
    Card candidate(crd[crdNum]);
    if(legalCheckS(candidate)){
        s[numOfSCrds]=crd[crdNum];
        if(numOfSCrds<12){
            numOfSCrds++;           //Increment counter.
        }
        else if(numOfSCrds==12){
            sFull=complete();
        }
        return true;
    }
    else{
        cout<<"Invalid move."<<endl;
        return false;
    }
}

bool Foundation::legalCheckC(Card crd){
    if(numOfCCrds==0){  //Ace check.
        if(crd.face()=='A'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfCCrds==1){
        if(crd.face()=='2'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfCCrds==2){
        if(crd.face()=='3'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfCCrds==3){
        if(crd.face()=='4'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfCCrds==4){
        if(crd.face()=='5'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfCCrds==5){
        if(crd.face()=='6'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfCCrds==6){
        if(crd.face()=='7'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfCCrds==7){
        if(crd.face()=='8'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfCCrds==8){
        if(crd.face()=='9'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfCCrds==9){
        if(crd.face()=='T'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfCCrds==10){
        if(crd.face()=='J'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfCCrds==11){
        if(crd.face()=='Q'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfCCrds==12){
        if(crd.face()=='K'){
            return true;
        }
        else{
            return false;
        }
    }
}

bool Foundation::legalCheckD(Card crd){
    if(numOfDCrds==0){  //Ace check.
        if(crd.face()=='A'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfDCrds==1){
        if(crd.face()=='2'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfDCrds==2){
        if(crd.face()=='3'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfDCrds==3){
        if(crd.face()=='4'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfDCrds==4){
        if(crd.face()=='5'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfDCrds==5){
        if(crd.face()=='6'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfDCrds==6){
        if(crd.face()=='7'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfDCrds==7){
        if(crd.face()=='8'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfDCrds==8){
        if(crd.face()=='9'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfDCrds==9){
        if(crd.face()=='T'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfDCrds==10){
        if(crd.face()=='J'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfDCrds==11){
        if(crd.face()=='Q'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfDCrds==12){
        if(crd.face()=='K'){
            return true;
        }
        else{
            return false;
        }
    }
}

bool Foundation::legalCheckH(Card crd){
    if(numOfHCrds==0){  //Ace check.
        if(crd.face()=='A'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfHCrds==1){
        if(crd.face()=='2'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfHCrds==2){
        if(crd.face()=='3'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfHCrds==3){
        if(crd.face()=='4'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfHCrds==4){
        if(crd.face()=='5'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfHCrds==5){
        if(crd.face()=='6'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfHCrds==6){
        if(crd.face()=='7'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfHCrds==7){
        if(crd.face()=='8'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfHCrds==8){
        if(crd.face()=='9'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfHCrds==9){
        if(crd.face()=='T'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfHCrds==10){
        if(crd.face()=='J'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfHCrds==11){
        if(crd.face()=='Q'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfHCrds==12){
        if(crd.face()=='K'){
            return true;
        }
        else{
            return false;
        }
    }
}

bool Foundation::legalCheckS(Card crd){
    if(numOfSCrds==0){  //Ace check.
        if(crd.face()=='A'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfSCrds==1){
        if(crd.face()=='2'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfSCrds==2){
        if(crd.face()=='3'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfSCrds==3){
        if(crd.face()=='4'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfSCrds==4){
        if(crd.face()=='5'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfSCrds==5){
        if(crd.face()=='6'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfSCrds==6){
        if(crd.face()=='7'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfSCrds==7){
        if(crd.face()=='8'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfSCrds==8){
        if(crd.face()=='9'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfSCrds==9){
        if(crd.face()=='T'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfSCrds==10){
        if(crd.face()=='J'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfSCrds==11){
        if(crd.face()=='Q'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(numOfSCrds==12){
        if(crd.face()=='K'){
            return true;
        }
        else{
            return false;
        }
    }
}

bool Foundation::complete(){
    return true;
}

bool Foundation::victory(){
    
}