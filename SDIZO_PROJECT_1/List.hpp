//
//  List.hpp
//  SDIZO_PROJECT_1
//
//  Created by Szymon Klimczuk on 24.02.2018.
//  Copyright © 2018 Szymon Klimczuk. All rights reserved.
//

#ifndef List_hpp
#define List_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class List
{
public:
    void readFromFile(string filename);
    void printList();
    
    void addAtBegin();
    void addAtMiddle();
    void addAtBottom();
    
    void deleteFirst();
    void deleteMiddle();
    void deleteLast();
    
    void findElement();
};

#endif /* List_hpp */
