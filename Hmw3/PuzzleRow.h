//
//  PuzzleRow.h
//  Hmw3
//
//  Created by Alper Bozkurt on 23.04.2022.
//

#ifndef PuzzleRow_h
#define PuzzleRow_h

class PuzzleRow{
private:
    struct PuzzlePiece{
        unsigned char shape;
        int rowindex;
        int colindex;
        PuzzlePiece* next;
};
    PuzzlePiece* head;
    PuzzleRow* next;
    int rowindex;
    int maxSize; //equals to puzzleContainer width
    
    //my private functions
    PuzzlePiece *find(int index);
    
public:
    // getPiece boş
    PuzzleRow( int size, int rowindex);
    ~PuzzleRow();
    int getRowIndex();
    void setNext( PuzzleRow* next );
    PuzzleRow* getNext();
    bool insert( int index, char shape );
    bool remove( int index );
    bool isEmpty();
    unsigned char getPiece(int index);
    void printRow();
    
    //my public functions
    int getLength();
    bool isPieceEmpty(int index);
    PuzzlePiece* findPrev(int index);
};
#endif /* PuzzleRow_h */
