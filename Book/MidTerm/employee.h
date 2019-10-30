/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   employee.h
 * Author: Matthew Borja
 * Created on October 29, 2019, 5:35 PM
 * Purpose: Contain the structure for problem 2.
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

struct Employee{
    std::string name;
    float payRate;
    int hours;
    float gross;
    std::string amount;
};

#endif /* EMPLOYEE_H */

