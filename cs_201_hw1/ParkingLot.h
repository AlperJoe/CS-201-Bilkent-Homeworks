//
//  ParkingLot.h
//  cs_201_hw1
//
//  Created by Alper Bozkurt on 23.03.2022.
//

#ifndef ParkingLot_h
#define ParkingLot_h

#include "Car.h"


class ParkingLot{
public:
    int** carList;
    ParkingLot();
    int getNoOfCar();
    int getLotID();
    int getRowNumber();
    int getColumnNumber();
    int getEmptyParkingSlots();
    void setParkingLot(int id, int row, int column);
    

private:
    int noOfCar;
    int parkingLotID;
    int rowNumber;
    int columnNumber;
    int emptyParkingLots;
    int** lotSlot;
};

#endif /* ParkingLot_h */
