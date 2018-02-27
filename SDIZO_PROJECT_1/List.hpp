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

struct listElement
{
    int data;
    listElement *next, *prev;
};

class List
{
private:
    listElement *tail, *head;
    int size;
public:
    List();
    ~List();
    
    bool readFromFile(string filename);
    void printList();
    
    void addAtBegin(int val, listElement *&head, listElement *&tail);
    void addAfterElement(int val, int index, listElement *&head, listElement *&tail);
    void addAtBottom(int val, listElement *&head, listElement *&tail);
    
    void deleteFirst();
    void deleteMiddle();
    void deleteLast();
    
    void findElement();
    
    int getSize();
};

#endif /* List_hpp */
