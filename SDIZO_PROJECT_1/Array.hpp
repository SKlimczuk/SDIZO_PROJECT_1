//
//  Array.hpp
//  SDIZO_PROJECT_1
//
//  Created by Szymon Klimczuk on 24.02.2018.
//  Copyright © 2018 Szymon Klimczuk. All rights reserved.
//

#ifndef Array_hpp
#define Array_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Array
{
private:
    int size;
    int *array;
public:
    Array();
    Array(int *array, int size);
    ~Array();
    
    bool readFromFile(string filename);
    void printArray();
    
    void addAtBegin(int val);
    void addAtMiddle(int val, int idx);
    void addAtBottom(int val);
    
    void deleteFirst();
    void deleteMiddle(int idx);
    void deleteLast();
    
    bool findElement(int element);
    
    int getSize();
};

#endif /* Array_hpp */
