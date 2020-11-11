//
//  main.cpp
//  CSC 326 Lab 5 Multiple Files
//
//  Created by Nicholas Pascalino on 4/27/20.
//  Copyright © 2020 Nicholas Pascalino. All rights reserved.
//

#include "Garage.h"
#include "Garage.cpp"

using namespace std;
int main()
{

    ifstream inFile;
    
    inFile.open("ParkingGarage.txt");
    
    if(!inFile)
    {
        cout << "inFile Error!" << endl;
        exit(1);
    }
    
    
    car * carEntry = new car[100]; // dynamic array for read in of cars
    int totalEntries = 0; // to see how long my park/ departure loop must run below
    
    cout << "All requests are currently being scanned in..." << endl;
            while(!inFile.eof())
            {
                inFile >> carEntry[totalEntries].status >> carEntry[totalEntries].licensePlate; // check to see if getline fucntion is needed
               
                   
                totalEntries++;
            }
            
    inFile.close();
    for (int i=0; i < totalEntries-1; i++)
    {
        cout << "License Plate Number: " << carEntry[i].licensePlate << " has been scanned in and is requesting: " ;
            if(carEntry[i].status == 'A')
                {
                    cout << "Arrival" << endl;
                }
            else if(carEntry[i].status == 'D')
                    cout << "Departure" << endl;
    }
            
    Garage <car> GarageOne;// street parking limit is different from other stacks(garages)
    GarageOne.changeLimit(100);
   
    for (int j=0; j < totalEntries; j++)
    {
       if(carEntry[j].status == 'A')
        {
           GarageOne.arrival(carEntry[j]);
        }
       else if(carEntry[j].status == 'D')
        {
            GarageOne.departure(carEntry[j]);
        }
  
    }
    return 0;
}
