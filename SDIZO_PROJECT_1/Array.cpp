//
//  Array.cpp
//  SDIZO_PROJECT_1
//
//  Created by Szymon Klimczuk on 24.02.2018.
//  Copyright © 2018 Szymon Klimczuk. All rights reserved.
//

#include "Array.hpp"

#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

Array::Array()
{
    this->array = nullptr;
    this->size = 0;
}

Array::Array(int *array, int size)
{
    this->array = array;
    this->size = size;
}

Array::~Array()
{
    delete[]array;
}

bool Array::readFromFile(string filename)
{
    int size = 0;
    int val;
    ifstream file;
    file.open(filename);
    if(file.is_open())
    {
        file >> size;
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
        cout << endl << "plik nie zostal poprawnie otworzony !" << endl;
        return false;
    }
    return true;
}

void Array::printArray()
{
    cout << endl << "----TABLICA----" << endl;
    cout << "Rozmiar : " << size << endl;
    for(int i=0;i<size;i++)
        cout << i+1 << " : " << array[i] << endl;
    cout << "---------------" << endl;
}

void Array::addAtBottom(int val)
{
    size++;
    int *temp_array = new int[size];

    for(int i=0;i<size-1;i++)
        temp_array[i] = array[i];
    delete []array;

    temp_array[size-1] = val;
    array = temp_array;
}

void Array::addAtMiddle(int val, int idx)
{
    if(idx >= size || idx < 0)
        cout << endl << "Niepoprawny indeks nowego elementu !" << endl;
    else
    {
        size++;
        int *temp_array = new int[size];
        
        for (int i=0; i<idx; i++)
            temp_array[i] = array[i];
        temp_array[idx] = val;
        for (int i=idx;i<size-1;i++)
            temp_array[i+1] = array[i];
        delete []array;
        
        array = temp_array;
    }
}

void Array::addAtBegin(int val)
{
    size++;
    int *temp_array = new int[size];
    
    for(int i=0;i<size-1;i++)
        temp_array[i+1] = array[i];
    delete []array;
    
    temp_array[0] = val;
    array = temp_array;
}

void Array::deleteFirst()
{
    if(size == 0)
        cout << endl << "Tablica jest pusta !" << endl;
    else
    {
        size--;
        int *temp_array = new int [size];
        
        for(int i=0;i<size;i++)
            temp_array[i] = array[i+1];
        delete []array;
        
        array = temp_array;
    }
}

void Array::deleteMiddle(int idx)
{
    if(size == 0)
        cout << endl << "Tablica jest pusta !" << endl;
    else if(idx < 0 && idx >= size)
        cout << endl << "Nieprawidlowy indeks !" << endl;
    else
    {
        size--;
        int *temp_array = new int [size];
        
        for(int i=0;i<idx;i++)
            temp_array[i] = array[i];
        for (int i=idx; i<size; i++)
            temp_array[i] = array[i+1];
        delete []array;
        
        array = temp_array;
    }
}

void Array::deleteLast()
{
    if(size == 0)
        cout << endl << "Tablica jest pusta !" << endl;
    else
    {
        size--;
        int *temp_array = new int [size];
        
        for(int i=0;i<size;i++)
            temp_array[i] = array[i];
        delete []array;
        
        array = temp_array;
    }
}

bool Array::findElement(int element)
{
    if(size == 0)
        cout << endl << "Tablica jest pusta !";
    else
    {
        for(int i=0;i<size;i++)
            if(array[i] == element)
                return true;
    }
    return false;
}

int Array::getSize()
{
    return size;
}
