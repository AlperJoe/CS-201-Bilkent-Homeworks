//
//  ParkingSystem.cpp
//  cs_201_hw1
//
//  Created by Alper Bozkurt on 23.03.2022.
//

#include <stdio.h>
#include "ParkingSystem.h"
#include <iostream>
using namespace std;

ParkingSystem::ParkingSystem(){
    noOfParkingLots= 0;
    parkingLotList = NULL;
    isWarningable =true;
}

ParkingSystem::~ParkingSystem(){
    delete[] parkingLotList;
}

void ParkingSystem::createLot(int id,int rows,int columns){
    if(noOfParkingLots == 0){
        parkingLotList = new ParkingLot[1];
        parkingLotList[0].setParkingLot(id,rows,columns);
        noOfParkingLots++;
    }
    else{
        isWarningable = false;
        for(int i = 0; i < noOfParkingLots; i++){
            if(parkingLotList[i].getLotID() == id){
                cout<<"There is parking lot with same id"<<endl;
                isWarningable = true;
            }
        }
        if(isWarningable){
            cout<<"it is warningable"<<endl;
        }
        else{
            ParkingLot* temp = parkingLotList;
            parkingLotList = new ParkingLot[noOfParkingLots + 1];
            for(int i = 0; i < noOfParkingLots; i++){
                parkingLotList[i] = temp[i];
            }
            parkingLotList[noOfParkingLots].setParkingLot(id,rows,columns);
            noOfParkingLots++;
            delete[] temp;
        }
        isWarningable = true;
    }
}
void ParkingSystem::removeLot(int id){
    if(noOfParkingLots == 0){
        cout<<"No Parking Lot exists"<<endl;
    }
    else{
        for(int i = 0; i < noOfParkingLots; i++){
            if(parkingLotList[i].getLotID() == id){
                isWarningable = false;
                
                //delete all the car inside
                for(int j = 0; j < parkingLotList[i].getNoOfCar(); j++){
                    removeCar(parkingLotList[i].carList[j].getPlateNumber()) ;
                }
                delete[] parkingLotList[i].carList;
                
                //delete parkingLot
                noOfParkingLot--;
                ParkingLot* temp = parkingLotList;
                parkingLotList = new ParkingLot[noOfParkingLot];
                
                int index = i;
                for(int k = 0; k < index; k++ ){
                    parkingLotList[k] = temp[k];
                }
                for(int l = index + 1; l < noOfParkingLot; l++){
                    parkingLotList[l - 1] = temp[l];
                }
                delete[] temp;
                cout<<"Selected Parking Lot has been deleted."<<endl;
            }
        }
        if(isWarningable){
            cout<<"Wrong ID"<<endl;
        }
        isWarningable = true;
    }
}
void ParkingSystem::listLots(){
    if(noOfParkingLots == 0){
        cout<<"No Parking Lots to List."<<endl;
    }
    else{
        for(int i = 0; i < noOfParkingLots; i++){
            cout<<parkingLots[i].getlotID()<<" "<<parkingLots[i].getRowNumber()<<" "<<parkingLots[i].getColumnNumber()<<" "<<parkingLots[i].getEmptyParkingSlots()<<endl
        }
    }
}
void ParkingSystem::lotContents(id){
    if(noOfParkingLots == 0){
        cout<<"No Parking Lots to List."<<endl;
    }
    else{
        for(int i = 0; i < noOfParkingLots[]; i++){
            if(id == parkingLotList[i].getLotID()){
                isWarningable = false;
                cout<<id<<" "<<parkingLots[i].getRowNumber()<<"  "<<parkingLots[i].getColumnNumber()<<" "<<parkingLots[i].getEmptyParkingSlots()<<endl
                //to display
                
            }
        }
        if(isWarningable){
            cout<<"Wrong ID"<<endl;
        }
        isWarningable = true;
    }
}
void ParkingSystem::parkCar(int lotId, string location, string carType, int plateNumber){
    if(noOfParkingLots == 0){
        cout<<"No Parking Lots to List."<<endl;
    }
    else{
        for(int i = 0; i < noOfParkingLots; i ++){
            if(lotID == parkingLotList[i].getLotID()){
                if(parkingLotList[i].getNoOfCar() == 0){
                    parkingLotList[i].carList = new Car[1];
                    parkingLotList[i].carList[0] = new Car(location,carType,plateNumber);
                }
                else{
                    for(int j = 0; i < parkingLotList.getNoOfCar(); j++){
                        if(parkingLotList[i].carList == plateNumber){
                            cout<<"it is existing plate number";
                            break;
                        }
                    }
                    Car* temp = parkingLotList[i].carList;
                    parkingLotList[i].carList = new Car [parkingLotList.getNoOfCar() + 1];
                    for(int k = 0; k < parkingLotList.getNoOfCar(); k++){
                        parkingLotList[k] = temp[k];
                    }
                    parkingLotList[i].getNoOfCar()++;
                    parkingLotList[i].carList[getNoOfCar()] = new Car(location,carType,plateNumber);
                    delete[] temp;
                }
            }
        }
    }
}
void ParkingSystem::findCar(int plateNumber){
    for(int i = 0; i < noOfParkingLots; i++){
        for(int i = 0; j < parkingLotList[i].getNoOfCar(); j++){
            if(parkingLotList[i].carList[j].getPlateNumber() == plateNumber){
                isWarningable = false;
                Car theCar = parkingLotList[i].carLis[j];
                cout<<parkingLotList[i].getLotID()<<" "<<theCar.getColumnNumber()<<" "<<theCar.getRowNumber()<<endl;
            }
        }
    }
    if(isWarningable){
        cout<<"No plate number exist"<<endl;
    }
    isWarningable = true;
}
void ParkingSystem::removeCar(int plateNumber){
    for(int i = 0; i < noOfParkingLots; i++){
        for(int j = 0; j < parkingLotList[i].getNoOfCar(); j++){
            if(parkingLotList[i].carList[j].getPlateNumber() == plateNumber){
                isWarningable = false;
                parkingLotList[i].getNoOfCar()--;
                Car* temp = parkingLotList[i].carList;
                parkingLotList[i].carList = new Car[parkingLotList[i].getNoOfCar()];
                
                int index = i;
                for(int k = 0; k < index; k++ ){
                    parkingLotList[i].carList[k] = temp[k];
                }
                for(int l = index + 1; l < noOfParkingLot; l++){
                    parkingLotList[i].carList[l-1] = temp[l];
                }
                delete[] temp;
                cout<<"Selected Parking Lot has been deleted."<<endl;
            }
        }
    }
    if(isWarningable){
        cout<<"No plate number exist"<<endl;
    }
    isWarningable = true;
}
