//
//  main.cpp
//  CSC 326 Lab 5 Multiple Files
//
//  Created by Nicholas Pascalino on 4/27/20.
//  Copyright © 2020 Nicholas Pascalino. All rights reserved.
//


#include "Garage.h"
using namespace std;

template <class T>
Garage <T> :: Stack:: Stack(): top(NULL)
{
}

template <class T>
Garage <T> :: Stack:: ~Stack()
{
    while(top!=NULL)
    {
    stackNode * delnode = top;
    top=top->nextCar;
    delnode->nextCar = NULL;
    delete delnode;
    delnode = nullptr;
    }
}

template <class T>
void Garage <T>:: Stack::push(const T &obj) // display cout correctly
{
    if(carCount < 10) // or carLimit for lane
    {
    stackNode * newnode = new stackNode;
    newnode-> carEntry = obj; // is this sufficient to copy data of car?
    newnode->nextCar = top;
    top = newnode; // not sure why this is done
    cout << newnode->carEntry.licensePlate << " has been successfuly parked or temporarily moved to the street." << endl;
    carCount++;
    }
    
    
    
}

template <class T>
T Garage <T> ::  Stack::pop(T &key, bool &success)
{
    success =top!=NULL;
    if(success)
    {
        key = top->carEntry;
        stackNode *delnode = top;
        top = top->nextCar;
        delnode->nextCar=NULL;
        delete delnode;
        delnode = nullptr;
        carCount--;
        return key;
    }
    else
        return key; // need a proper return type, maybe a car with all 0s as license plate for error
}

template <class T>
int Garage <T> :: Stack :: search(T &anEntry) const
{
    stackNode * current = top;
    int index = carCount;
    while (current && current->carEntry.licensePlate != anEntry.licensePlate)
    {
        current= current->nextCar;
        index--;
    }
    if (current) return index;
    return 0;
}

template <class T>
void Garage <T> :: arrival(T &anEntry)
{
    if(laneOne.carCount < laneOne.carLimit)
        {
            cout << "Car with license plate number: " << anEntry.licensePlate << " is requesting arrival at Lane One of the garage." << endl;
            laneOne.push(anEntry);
            anEntry.movements+=1;
        }
    else if(laneOne.carCount == laneOne.carLimit && laneTwo.carCount < laneTwo.carLimit)
        {
            cout << "Car with license plate number: " << anEntry.licensePlate << " is requesting arrival at Lane Two of the garage." << endl;
                       laneTwo.push(anEntry);
            anEntry.movements+=1;
        }
    else if(laneOne.carCount == laneOne.carLimit && laneTwo.carCount == laneTwo.carLimit)
        {
        
             cout << "Our garage is full. We apologize for the inconvenience." << endl;
        }
}

template <class T>
void Garage <T>:: departure(T & anEntry)
{
    car transferKey; // key to store value returned by pop and used for push. this applies to cars being moved for departure of other cars.
    
//for (int i=0; i < 10; i++)
//{
   
   
        
           // for (int i = carLimit; i < lanePositive.search(anEntry); i--) // need to make sure only space in negative lane is taken and not more is tried, rest popped onto street
     
    if(laneOne.search(anEntry) != 0)
    {
    cout << "Car with license plate number: " << anEntry.licensePlate << " is being requested for departure from Garage 1." << endl;
            for(int i = laneOne.carCount; i > laneOne.search(anEntry); i--) // make sure that I don't pop the car I need, make sure loop works with search fucntion correct numbers
            {
                // figure out how to access the top car through linked list
                    if(laneTwo.carCount<laneTwo.carLimit)
                    {
                        laneTwo.push(laneOne.pop(transferKey, success));
                        transferKey.movements++;
                    }
                    else
                    {
                            streetParking.push(laneOne.pop(transferKey,success));
                            transferKey.movements++;
                    }
            }
               
            cout << "The car with license plate number: " << anEntry.licensePlate << " has been located and is being removed from the garage."  << endl;
            laneOne.pop(transferKey,success);
            cout << "The car was moved " << anEntry.movements << " times to a second garage or outside while parked at the garage" << endl;
                
            
                if(streetParking.carCount > 0)
                {
                    for (int i = streetParking.carCount; i >0; i--)
                    {
                    laneOne.push(streetParking.pop(transferKey,success));
                    transferKey.movements++;
                    }
                    cout << "The cars parked on the street have been moved back to the garage." << endl;
                
                    }
  
    }
    else if(laneTwo.search(anEntry) != 0)
       {
        cout << "Car with license plate number: " << anEntry.licensePlate << " is being prepared for departure from Garage 2." << endl;
               for(int i = laneTwo.carCount; i > laneTwo.search(anEntry); i--) // make sure that I don't pop the car I need, make sure loop works with search fucntion correct numbers
               {
                   // figure out how to access the top car through linked list
                       if(laneOne.carCount<laneOne.carLimit)
                       {
                           laneOne.push(laneTwo.pop(transferKey, success));
                           transferKey.movements++;
                       }
                       else
                       {
                               streetParking.push(laneTwo.pop(transferKey,success));
                               transferKey.movements++;
                       }
               }
                   
                       cout << "The car with license plate number: " << anEntry.licensePlate;
                       laneTwo.pop(transferKey,success);
                       cout << " has been located and removed from the garage." << endl;
                       cout << "The car was moved " << anEntry.movements << " times to a second garage or outside while parked at the garage" << endl;
    
               
                   if(streetParking.carCount > 0)
                   {
                       for (int i = streetParking.carCount; i >0; i--)
                       {
                       laneTwo.push(streetParking.pop(transferKey,success));
                       transferKey.movements++;
                       }
                       cout << "The cars parked on the street have been moved back to the garage." << endl;
                       
                   
                   }
     
       }
    else
    {
        cout << "The car with license plate number: " << anEntry.licensePlate  << " is not parked in this garage." << endl;
    }
}

template <class T>
void Garage <T> :: changeLimit(int limitChange)
{
    streetParking.carLimit = limitChange;
    cout << "The number of cars that the street can hold has been updated to: " << limitChange << endl;
}
