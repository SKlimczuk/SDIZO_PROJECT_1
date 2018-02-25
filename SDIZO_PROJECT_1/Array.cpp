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
    this->head = nullptr;
    this->size = 0;
}

Array::Array(int *array, int size)
{
    this->head = array;
    this->size = size;
}

Array::~Array()
{
    delete[]head;
}

bool Array::readFromFile(string filename)
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
            for(int i = 0; i <= size; i++)
            {
                //operacja dodania na koniec struktury
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

void Array::printArray()
{
    
}
