//
//  Garage.h
//  CSC 326 Lab 5 Multiple Files
//
//  Created by Nicholas Pascalino on 4/27/20.
//  Copyright © 2020 Nicholas Pascalino. All rights reserved.
//
#ifndef GARAGE_H
#define GARAGE_H



#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct car{ // struct wherre car plates and status are stroed from .txt, done as dynamic array of structs
    char status;
    string licensePlate;
    int movements=0;
};



template <class T>
class Garage
{
private:
    class Stack
    {
    public:
        Stack(); // Constructor to create lanes and street, must give automatic size for garage lanes
        ~Stack(); // destructor at end of file
        void push(const T &obj); // push car into garage lane(stack)
        T pop(T &key ,bool &success); //pop car from garaage lane(stack)
        int search(T &anEntry) const; // check for car in garage lane(stack)
        int carCount = 0;
        int carLimit = 10;
        // int carLimit = 10; // not sure if this was ever used
    private:
        struct stackNode{
            car carEntry; // must decide if this should be a pointer, left as is, or somehow made a copy constructor
            stackNode * nextCar;
        };
        stackNode *top, current; // pointer to top of the stack (front of garage)
        
    } laneOne,laneTwo,streetParking ;
    /*
    Stack laneOne;
    Stack laneTwo;
    Stack streetParking;
     */
    
public:
    void departure(T &anEntry);
    void arrival(T &anEntry);
    void changeLimit(int limitChange);
    bool success; // actual parameter for pop()
    
};

#endif
