//
//  List.cpp
//  SDIZO_PROJECT_1
//
//  Created by Szymon Klimczuk on 24.02.2018.
//  Copyright © 2018 Szymon Klimczuk. All rights reserved.
//

#include "List.hpp"

#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

List::List()
{
    
}

List::~List()
{
    
}

bool List::readFromFile(string filename)
{
    int size = 0;
    ifstream file;
    file.open(filename, ios::in);
    if(file.good())
    {
        file>>size;
        if(size == 0)
        {
            cout << endl << "rozmiar jest nieprawidlowy !" << endl;
            return false;
            }
            else {
                for(int i = 0; i < size; i++)
                {
                    //operacja dodanie do struktury
                }
            }
            file.close();
            }
            else {
                cout << endl << "plik nie zostal poprawnie otwarty !" << endl;
                return false;
            }
            return true;
}

void List::printList()
{
    
}

void List::addAtBegin(int val, listElement *&head, listElement *&tail)
{
    listElement *temp = new listElement;
    temp->data = val;
    temp->next = head;
    temp->prev = nullptr;
    
    if(head -> next)
        head->prev = temp;
    else
    {
        cout << endl << "Lista jest pusta !" << endl;
        head = temp;
        tail = temp;
    }
    size++;
    head = temp;
}

void List::addAfterElement(int val, int index, listElement *&head, listElement *&tail)
{
    if(index >= size)
        cout << endl << "Index nie moze byc wiekszy niz rozmiar listy !" << endl;
    else
    {
        listElement *temp = new listElement;
        temp->data = val;
        //brakuje jescze ustawienia wskaznikowa na odpowiednich polach
        
        if(index == size-1)
            addAtBottom(val, head, tail);
        else
        {
            //brak implementacji;
            size++;
        }
    }
}

void List::addAtBottom(int val, listElement *&head, listElement *&tail)
{
    listElement *temp = new listElement;
    temp->data = val;
    temp->next = nullptr;
    temp->prev = tail;
    
    if(tail->prev)
        tail->next = temp;
    else
    {
        cout << endl << "Lista jest pusta !" << endl;
        head = temp;
        tail = temp;
    }
    size++;
    tail = temp;
}

int List::getSize(){return size;}

