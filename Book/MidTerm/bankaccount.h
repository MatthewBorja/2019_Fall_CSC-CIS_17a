/* 
 * File:   bankaccount.h
 * Author: Matthew Borja
 * Created on October 28, 2019, 9:50 PM
 * Purpose: Contain the structure for problem 1.
 */

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H


struct Account{
    std::string name;
    std::string address;
    char acctNum[5];
    int bal=0;
    int totChck=0;
    int totDep=0;
};

#endif /* BANKACCOUNT_H */

