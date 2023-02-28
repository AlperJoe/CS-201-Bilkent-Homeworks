//
//  PuzzleContainer.cpp
//  Hmw3
//
//  Created by Alper Bozkurt on 24.04.2022.
//

#include <stdio.h>
#include "PuzzleContainer.h"
#include <iostream>

using namespace std;

void shapeConverter(unsigned char shape, int& down, int& up, int& right, int& left){
    down = shape%4;
    up = (shape/4)%4;
    right= (shape/16)%4;
    left= shape/64;
}

PuzzleContainer::PuzzleContainer(int h, int w){
    height = h;
    width = w;
    for(int i = 1; i <= height; i++){
        insertRow(i);
    }
}

PuzzleContainer::~PuzzleContainer(){
    for(int i = 1; i <= height; i++){
        insertRow(i);
    }
}

bool PuzzleContainer::insertRow(int index){
    if((index < 1)||(height < index)){
        return false;
    }
    PuzzleRow *newPtr = new PuzzleRow(width,index);
    if(index == 1){
        newPtr->setNext(NULL);
        rowLists = newPtr;
    }
    else{
        PuzzleRow *prev = getRow(index - 1);
        newPtr -> setNext(prev -> getNext());
        prev ->setNext(newPtr);
    }
    return true;
}

PuzzleRow* PuzzleContainer::getRow(int index){
    if((index < 1) ||(index > height)){
        return NULL;
    }
    else{
        PuzzleRow *cur = rowLists;
        for(int skip = 1; skip < index; skip++){
            cur = cur -> getNext();
        }
        //cout << cur->getRowIndex();
        return cur;
    }
}
bool PuzzleContainer::isCompatible(int no1, int no2){
    if(no1 == 1){
        //cout<<"should be hole"<<endl;
        return no2 == 0;
    }
    if(no1 == 0){
        //cout<<"should be knob"<<endl;
        return no2 == 1;
    }
    return false;
}

bool PuzzleContainer::removeRow( int index ){

    PuzzleRow* cur;
    
    if(index < 1 || index > height){
        return false;
    }
    height--;
    if(index == 1){
        cur = rowLists;
        rowLists = rowLists -> getNext();
    }
    else{
        cur = getRow(index);
        PuzzleRow *prev = getRow(index - 1);
        prev -> setNext(cur -> getNext());
    }
    cur -> setNext(NULL);
    delete cur;
    cur = NULL;
    return true;
   
}
//methods we will be evaluated
void PuzzleContainer::displayContainer(){
    cout<<"Container "<< height<< "x" << width <<":"<<endl;
    cout<<"  ";
    for(int i = 1; i <= width; i++){
        cout<<i<<" ";
    }
    cout<<endl;
    int counter = 1;
    for(PuzzleRow* cur = rowLists; cur != NULL; cur = (cur -> getNext())){
        cout<<counter<< " ";
        cur -> printRow();
        counter++;
    }
}

bool PuzzleContainer::addPiece( int row, int col , char shape ){
    if((height < row)||(width < col)||(col < 1)||(row < 1)){
        cout << "("<< row <<","<<col<< ") is out of frame, it cannot be added"<<endl;
        return false;
    }
    PuzzleRow* curRow = getRow(row);
    if(!(curRow -> isPieceEmpty(col))){
        cout<< "("<< row <<","<<col << ") has been already occupied, it cannot be added "<<endl;
        return false;
    }
    
    int down, up, right, left;
    shapeConverter(shape, down, up, right, left);
    
   
    if(width >= col + 1){
        unsigned char rightTemp = curRow->getPiece(col + 1);
        
        if(rightTemp != 255){
            //cout<<rightTemp<<endl;
            int downR, upR, rightR, leftR;
            shapeConverter(rightTemp, downR, upR, rightR, leftR);
            if(!(isCompatible(right, leftR))){
                cout<< "Shape doesn't fit into ("<< row <<","<<col<< "), it cannot be added"<<endl;
                return false;
            }
        }
    }
    else{
        if(right != 2){
            cout<< "Shape doesn't fit into ("<< row <<","<<col<< "), it cannot be added"<<endl;
            return false;
        }
        
    }
    
     if(1 <= col - 1){
         unsigned char leftTemp = curRow->getPiece(col - 1);
         if(leftTemp != 255){
             //cout<<leftTemp<<endl;
             int downL, upL, rightL, leftL;
             shapeConverter(leftTemp, downL, upL, rightL, leftL);
             if(!(isCompatible(left, rightL))){
                 cout<< "Shape doesn't fit into ("<< row <<","<<col<< "), it cannot be added"<<endl;
                 return false;
             }
         }
     }
     else{
         if(left != 2){
             cout<<"Shape doesn't fit into ("<< row <<","<<col<< "), it cannot be added"<<endl;
             return false;
         }
     }
    
    if(1 <= row - 1){
        PuzzleRow* upRow = getRow(row - 1);
        unsigned char upTemp = upRow->getPiece(col);
        if(upTemp != 255){
            //cout<<upTemp<<endl;
            int downU, upU, rightU, leftU;
            shapeConverter(upTemp, downU, upU, rightU, leftU);
            if(!(isCompatible(up, downU))){
                cout<< "Shape doesn't fit into ("<< row <<","<<col<< "), it cannot be added"<<endl;
                return false;
            }
        }
    }
    else{
        if(up != 2){
            cout<< "Shape doesn't fit into ("<< row <<","<<col<< "), it cannot be added"<<endl;
            return false;
        }
    }
    
    if(height >= row + 1){
        PuzzleRow* downRow = getRow(row + 1);
        unsigned char downTemp = downRow->getPiece(col);
        if(downTemp != 255){
            //cout<<downTemp<<endl;
            int downD, upD, rightD, leftD;
            shapeConverter(downTemp, downD, upD, rightD, leftD);
            if(!(isCompatible(down, upD))){
                cout<< "Shape doesn't fit into ("<< row <<","<<col<< "), it cannot be added"<<endl;
                return false;
            }
        }
    }
    else{
        if(down != 2){
            cout<< "Shape doesn't fit into ("<< row <<","<<col<< "), it cannot be added"<<endl;
            return false;
        }
    }
    curRow -> insert(col, shape);
    cout<<"A piece is added to ("<< row <<","<<col<<")"<<endl;
    return true;
}

bool PuzzleContainer::removePiece(int row, int col){
    if((height < row)||(width < col)||(col < 1)||(row < 1)){
        cout << "("<< row <<","<<col<< ") is out of frame, it cannot be removed"<<endl;
        return false;
    }
    
    PuzzleRow* cur = getRow(row);
    unsigned char curPiece = cur ->getPiece(col);
    if(curPiece == 255){
        cout<<"There is no piece on ("<< row << ","<< col<< "), it cannot be removed"<<endl;
        return false;
    }
    cur -> remove(col);
    cout<<"The piece on ("<< row << ","<< col<< ") is removed"<<endl;
    return true;
}

void PuzzleContainer::showPiece(int row,int col){
    
    if((height < row)||(width < col)||(col < 1)||(row < 1)){
        cout << "("<< row <<","<<col<< ") is out of frame, it cannot be showed"<<endl;
        return;
    }
    
    PuzzleRow* cur = getRow(row);
    unsigned char curPiece = cur ->getPiece(col);
    if(curPiece == 255){
        cout<<"There is no piece on ("<< row << ","<< col<< "), it cannot be shown"<<endl;
        return;
    }
    int up,down,right,left;
    shapeConverter(curPiece,down, up, right, left);
    switch (down) {
        case 0:
            cout << "Down: Hole"<<endl;
            break;
        case 1:
            cout << "Down: Knob"<<endl;
            break;
        case 2:
            cout << "Down: Border"<<endl;
            break;
        default:
            break;
    }
    switch (up) {
        case 0:
            cout << "Up: Hole"<<endl;
            break;
        case 1:
            cout << "Up: Knob"<<endl;
            break;
        case 2:
            cout << "Up: Border"<<endl;
            break;
        default:
            break;
    }
    switch (right) {
        case 0:
            cout << "Right: Hole"<<endl;
            break;
        case 1:
            cout << "Right: Knob"<<endl;
            break;
        case 2:
            cout << "Right: Border"<<endl;
            break;
        default:
            break;
    }
    switch (left) {
        case 0:
            cout << "Left: Hole"<<endl;
            break;
        case 1:
            cout << "Left: Knob"<<endl;
            break;
        case 2:
            cout << "Left: Border"<<endl;
            break;
        default:
            break;
    }
}
void PuzzleContainer::showColumn(int col){
    if((width < col)||(col < 1)){
        cout << "Column "<<col <<" is out of border"<<endl;
        return;
    }
    
    cout<<"Column "<<col<<":"<<endl;
    for(PuzzleRow* cur = rowLists; cur != NULL; cur = cur -> getNext()){
        unsigned char ch = cur -> getPiece(col);
        if(ch == 255){
            cout<<"o"<<endl;
        }
        else{
            cout<<"x"<<endl;
        }
    }
}
void PuzzleContainer::showRow(int row){
    if((height < row)||(row < 1)){
        cout << "Row "<< row << " is out of border"<<endl;
        return;
    }
    cout << "Row "<< row <<":"<<endl;
    PuzzleRow* theRow = getRow(row);
    theRow -> printRow();
}
void PuzzleContainer::findPiece(char shape){
    bool booYaa = false;
    for(PuzzleRow* cur = rowLists; cur != NULL; cur = cur -> getNext()){
        for(int i = 1; i < cur -> getLength(); i ++){
            if(cur -> getPiece(i) == shape){
                cout<<"("<<cur->getRowIndex()<< ","<< i <<") ";
                booYaa = true;
            }
        }
    }
    if(booYaa)
        cout<< "contain the piece that has shape"<<endl;
    else{
        cout<<"There is no piece that has shape"<<endl;
    }
    int up,down,right,left;
    shapeConverter(shape,down, up, right, left);
    switch (down) {
        case 0:
            cout << "Down: Hole"<<endl;
            break;
        case 1:
            cout << "Down: Knob"<<endl;
            break;
        case 2:
            cout << "Down: Border"<<endl;
            break;
        default:
            break;
    }
    switch (up) {
        case 0:
            cout << "Up: Hole"<<endl;
            break;
        case 1:
            cout << "Up: Knob"<<endl;
            break;
        case 2:
            cout << "Up: Border"<<endl;
            break;
        default:
            break;
    }
    switch (right) {
        case 0:
            cout << "Right: Hole"<<endl;
            break;
        case 1:
            cout << "Right: Knob"<<endl;
            break;
        case 2:
            cout << "Right: Border"<<endl;
            break;
        default:
            break;
    }
    switch (left) {
        case 0:
            cout << "Left: Hole"<<endl;
            break;
        case 1:
            cout << "Left: Knob"<<endl;
            break;
        case 2:
            cout << "Left: Border"<<endl;
            break;
        default:
            break;
    }
}


