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
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

List::~List()
{
    delete head;
    delete tail;
    size = 0;
}

bool List::readFromFile(string filename)
{
    int size = 0;
    int val;
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
                    file >> val;
                    addAtBottom(val);
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
    int el_counter = 0;
    listElement *temp = head;
    
    if(temp == nullptr)
        cout << endl << "Lista jest pusta !" << endl;
    else
    {
        cout << endl << "-----------------" << endl;
        cout << "** rozmiar : " << getSize() << " **" << endl;
        
        while(temp)
        {
            cout << el_counter+1 << " : " << temp->data << endl;
            el_counter++;
            temp = temp->next;
        }
    }
}

void List::addAtBegin(int val)
{
    listElement *temp = new listElement;
    temp->data = val;
    temp->next = head;
    temp->prev = nullptr;
    head = temp;
    size++;
    if(temp->next)
        temp->next->prev = temp;
    else
        tail = temp;
}

void List::addAfterElement(int val, int idx)
{
    if(idx >= size)
        cout << endl << "Index nie moze byc wiekszy niz rozmiar listy !" << endl;
    else
    {
        if(idx == size-1)
        {
            addAtBottom(val);
        }
        else
        {
            listElement *temp = new listElement;
            listElement *add_after = head;
            temp->data = val;
            while(idx != 0)
            {
                add_after = add_after->next;
                idx--;
            }
            temp->next = add_after->next;
            temp->prev = add_after;\
            size++;
            add_after->next->prev = temp;
            add_after->next = temp;
        }
    }
}

void List::addAtBottom(int val)
{
    listElement *temp = new listElement;
    temp->data = val;
    temp->next = nullptr;
    temp->prev = tail;
    tail = temp;
    size++;
    if(temp->prev)
        temp->prev->next = temp;
    else
        head = temp;
}

void List::deleteFirst()
{
    if(!head)
        cout << endl << "Lista jest pusta !" << endl;
    else
    {
        if(head->next)
        {
            size--;
            head->next->prev=nullptr;
            head = head->next;
        }
        else
        {
            size--;
            head = tail = nullptr;
        }
    }
}

void List::deleteMiddle(int idx)
{
    if(!head)
        cout << endl << "Lista jest pusta !" << endl;
    else if(idx >= size)
        cout << endl << "Nieprawidlowy indeks !" << endl;
    else
    {
        listElement *el_to_remove = head;
        
        int i = 0;
        while(i != idx)
        {
            el_to_remove = el_to_remove->next;
            i++;
        }
        if(!el_to_remove->prev)
            deleteFirst();
        else if(!el_to_remove->next)
            deleteLast();
        else
        {
            size--;
            el_to_remove->prev->next = el_to_remove->next;
            el_to_remove->next->prev = el_to_remove->prev;
        }
        delete el_to_remove;
    }
}

void List::deleteLast()
{
    if(!head)
    {
        cout << endl << "Lista jest pusta !" << endl;
    }
    else
    {
        if(tail->prev)
        {
            size--;
            tail->prev->next = nullptr;
            tail = tail->prev;
        }
        else
        {
            size--;
            head = tail = nullptr;
        }
    }
}

bool List::findElement(int val)
{
    listElement *temp = head;
    while(temp)
    {
        if(temp->data == val)
            return true;
        temp = temp->next;
    }
    return false;
}

int List::getSize(){return size;}

