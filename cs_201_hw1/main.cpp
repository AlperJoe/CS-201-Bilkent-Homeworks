//
//  main.cpp
//  cs_201_hw1
//
//  Created by Alper Bozkurt on 23.03.2022.
//
#include <iostream>
using namespace std;
#include "ParkingSystem.h"
#include "ParkingLot.h"
#include "main.h"

int main(){
        ParkingSystem L;
        //L.listLots();
        // Testing add parking lot
        cout << endl;
        cout << "Testing add parking lots" << endl;
        cout << endl;
        L.createLot(980, 7, 7);
        L.createLot(666, 6, 11);
        L.createLot(222, 12, 12);
        cout << endl;
        L.createLot(434, 13, 3);
        L.createLot(222, 5, 4);
        L.createLot(301, 9, 9);
        cout << endl;
        L.createLot(301, 19, 3);
        L.createLot(205, 4, 4);
        cout << endl;
}
