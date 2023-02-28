//
//  Car.h
//  cs_201_hw1
//
//  Created by Alper Bozkurt on 23.03.2022.
//

#ifndef Car_h
#define Car_h
#include <string>

class Car{
public:
    Car();
    Car(string location,string carType,int plateNumber);
    int getPlateNumber();
    int getRowNumber();
    int getColumnNumber();
private:
    int plateNumber;
    string carType;
    string location;
    int lotID;
    int rowNumber;
    int columnNumber;
};

#endif /* Car_h */
