//
//  PuzzleRow.cpp
//  Hmw3
//
//  Created by Alper Bozkurt on 23.04.2022.
//

#include <stdio.h>
#include "PuzzleRow.h"
#include <iostream>

using namespace std;

PuzzleRow::PuzzleRow(int size, int rowindex){
    
    //initialize maxSize with the given value
    this -> maxSize = size;
    this -> rowindex = rowindex;
    
    //initialize head and next pointer to null
    head = NULL;
    next = NULL;
}

PuzzleRow::~PuzzleRow(){
    //delete every piece in that row
    while(!isEmpty()){
        remove(head->colindex);
   }
}

//getters and setters
void PuzzleRow::setNext( PuzzleRow* next ){
    this -> next = next;
}
PuzzleRow* PuzzleRow::getNext(){
    return next;
}
int PuzzleRow::getRowIndex(){
    return rowindex;
}


bool PuzzleRow::insert(int index, char shape){
    
    //no insert if the given index is smaller than 1 or bigger than row's size
    if((index < 1)||(index > maxSize)){
        return false;
    }
    
    //creates a new ptr
    PuzzlePiece *newPtr = new PuzzlePiece;

    //newPtr point to the attributes that puzzle piece have
    newPtr -> shape = shape;
    newPtr -> colindex = index;
    newPtr -> rowindex = rowindex;
    
    //if it is the first PuzzlePiece in that row
    if(head == NULL){
        //newPtr's next equals to head then head becomes newPtr
        newPtr -> next = head;
        head = newPtr;
    }
    else{
        //
        PuzzlePiece *prev = findPrev(index);
        newPtr -> next = prev -> next;
        prev -> next = newPtr;
    }
    return true;
}

bool PuzzleRow::remove(int index){
    PuzzlePiece *cur;
    if((index < 1) || (index > maxSize)){
        return false;
    }
    if(head -> colindex == index){
        cur = head;
        head = head -> next;
    }
    else{
        PuzzlePiece *prev = findPrev(index);
        //cout<<prev -> colindex;
        cur = prev -> next;
        prev -> next = cur -> next;
    }
    cur -> next = NULL;
    delete cur;
    cur = NULL;
    return true;
}

bool PuzzleRow::isEmpty(){
    return head == NULL;
}

unsigned char PuzzleRow::getPiece(int index){
    if((index < 1) ||(index > getLength())){
        return NULL;
    }
    else{
        for(PuzzlePiece* cur = head; cur != NULL; cur = cur -> next){
            if(index == cur -> colindex){
                return cur -> shape;
            }
        }
        return 255;
    }
}

void PuzzleRow::printRow(){
    for(int i = 1; i <= maxSize; i++){
        if(find(i) == NULL){
            cout<<"o ";
        }
        else{
            cout<<"x ";
        }
    }
    cout<<endl;
}

PuzzleRow::PuzzlePiece *PuzzleRow::find(int index){
    if((index < 1) ||(index > getLength())){
        return NULL;
    }
    else{
        for(PuzzlePiece* cur = head; cur != NULL; cur = cur -> next){
            if(index == cur -> colindex){
                return cur;
            }
        }
        return NULL;
    }
}

int PuzzleRow::getLength(){
    return maxSize;
}

bool PuzzleRow:: isPieceEmpty(int index){
    PuzzlePiece* curPiece = find(index);
    if(curPiece == NULL){
        return true;
    }
    return false;
}

PuzzleRow::PuzzlePiece* PuzzleRow::findPrev(int index){
    if((index < 1) ||(index > maxSize)){
        return NULL;
    }
    else{
        PuzzlePiece* prev = head;
        for(PuzzlePiece* cur = head -> next; cur != NULL; cur = cur -> next){
            if(cur -> colindex >= index)
                return prev;
            prev = cur;
        }
        return prev;
    }
}
