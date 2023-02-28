//
//  ParkingLot.cpp
//  cs_201_hw1
//
//  Created by Alper Bozkurt on 23.03.2022.
//

#include <stdio.h>
#include "ParkingLot.h"

ParkingLot::ParkingLot(){
    int parkingLotID = 0;
    int rowNumber = 0;
    int columnNumber = 0;
    int carListSize = 0;
}
int ParkingLot::getNoOfCar(){
    return this-> noOfCar;
}
int ParkingLot::getLotID(){
    return parkingLotID;
}
int ParkingLot::getRowNumber(){
    return rowNumber;
}
int ParkingLot::getColumnNumber(){
    return columnNumber;
}
int ParkingLot::getEmptyParkingLots(){
    return rowNumber * columnNumber - noOfCar;
}

void ParkingLot::setParkingLot(int id, int row, int column){
    this -> parkingLotID = id ;
    this -> rowNumber = row;
    this -> columnNumber = column;
}
