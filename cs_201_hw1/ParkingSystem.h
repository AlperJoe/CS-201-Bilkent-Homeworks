//
//  ParkingSystem.h
//  cs_201_hw1
//
//  Created by Alper Bozkurt on 23.03.2022.
//

#ifndef ParkingSystem_h
#define ParkingSystem_h
#include <iostream>
#include "ParkingLot.h"
#include "Car.h"
using namespace std;

class ParkingSystem{
public:
    ParkingSystem();
    ~ParkingSystem();
    
    void createLot(int lotid, int rows, int columns);
    void removeLot(int id);
    void listLots();
    void lotContents(int id);
    void parkCar(int lotId, string location, string carType, int plateNumber);
    void findCar(int plateNumber);
    void removeCar(int plateNumber);

private:
    int noOfParkingLots;
    ParkingLot* parkingLotList;
    bool isWarningable;
};

#endif /* ParkingSystem_h */
