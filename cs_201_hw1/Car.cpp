//
//  Car.cpp
//  cs_201_hw1
//
//  Created by Alper Bozkurt on 23.03.2022.
//

#include <stdio.h>
#include "Car.h"

Car::Car(){
    plateNumber = 0;
    string carType;
    string location;
    int lotID;
    int rowNumber;
    int columnNumber;
}
Car::Car(string location,string carType,int plateNumber){
    this -> location = location;
    this -> carType = carType;
    this -> plateNumber = plateNumber;
}
int Car::getPlateNumber(){
    return this -> plateNumber;
}
