//
//  PuzzleContainer.h
//  Hmw3
//
//  Created by Alper Bozkurt on 23.04.2022.
//

#ifndef PuzzleContainer_h
#define PuzzleContainer_h

#include "PuzzleRow.h"


class  PuzzleContainer{
private:
    PuzzleRow* rowLists;
    int height;
    int width;
    
    //my private variables
    PuzzleContainer*  next;
    
public:
    PuzzleContainer(int h, int w);
    ~PuzzleContainer();
    PuzzleRow* getRow( int index );
    bool insertRow( int index );
    bool removeRow( int index );
    bool addPiece( int row, int col , char shape );
    bool removePiece(int row, int col);
    int getHeight();
    int getWidth();
    void showPiece(int row, int col);
    void displayContainer();
    void showColumn(int col);
    void showRow(int row);
    void findPiece(char shape);
    
    //my public functions
    bool isCompatible(int no1, int no2);
};



#endif /* PuzzleContainer_h */
