//
//  Heap.hpp
//  SDIZO_PROJECT_1
//
//  Created by Szymon Klimczuk on 01.03.2018.
//  Copyright © 2018 Szymon Klimczuk. All rights reserved.
//

#ifndef Heap_hpp
#define Heap_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Heap
{
private:
    int size;
    int *heap_array;
    string cr,cl,cp;
public:
    Heap();
    ~Heap();
    
    bool readFromFile(string filename);
    void printHeap(string sp, string sn, int v);
    
    void addElement(int val);
    void removeElement();
    bool findElement(int val);
    
    int getSize();
};

#endif /* Heap_hpp */
