//
//  Heap.cpp
//  SDIZO_PROJECT_1
//
//  Created by Szymon Klimczuk on 01.03.2018.
//  Copyright © 2018 Szymon Klimczuk. All rights reserved.
//

#include "Heap.hpp"

#include <stdio.h>
#include <iostream>
#include <fstream>1

Heap::Heap()
{
    this->size = 0;
    this->heap_array = new int[size];
    
    this->cr = this->cl = this->cp = "  ";
    this->cr[0] = '218';
    this->cr[1] = '196';
    this->cl[0] = '192';
    this->cl[1] = '196';
    this->cp[0] = '179';
}

Heap::~Heap()
{
    delete[]heap_array;
    this->size=NULL;
}

bool Heap::readFromFile(string filename)
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
                addElement(val);
            }
        }
        file.close();
    }
    else {
        cout << endl << "plik nie zostal poprawnie otworzony !" << endl;
        return false;
    }
    return true;}

void Heap::printHeap(string sp, string sn, int v)
{
    /*
    string s;
    
    if(v < size)
    {
        s = sp;
        if(sn == cr) s[s.length() - 2] = ' ';
        printHeap(s + cp, cr, 2 * v + 2);
        
        s = s.substr(0,sp.length()-2);
        
        cout << s << sn << heap_array[v] << endl;
        
        s = sp;
        if(sn == cl) s[s.length() - 2] = ' ';
        printHeap(s + cp, cl, 2 * v + 1);
    }
    */
   
    cout << endl << "rozmiar : " << size << endl;
    for(int i=0;i<size;i++)
    {
        cout << endl << i+1 << " : " << heap_array[i];
    }
}

void Heap::addElement(int val)
{
    if(size == 0)
    {
        heap_array[0] = val;
        size++;
    }
    else
    {
    
        int i = size++;         //powiekszenie o jeden element
        int j = (i - 1) / 2;    //indeks rodzica
        
        while(i > 0 && heap_array[j] < val)
        {
            heap_array[i] = heap_array[j];
            i = j;
            j = (i - 1) / 2;
        }
        
        heap_array[i] = val;
    }
}

void Heap::removeElement()
{
    if(size == 0)
        cout << endl << "Kopiec jest pusty !" << endl;
    else
    {
        int temp = heap_array[size-1];
        size--;
        int i = 0;
        int j = 1;
        
        while(j < size)
        {
            //j + 1 < n && T[j + 1] > T[j]
            if(j+1 < size && heap_array[j+1] > heap_array[j])
                j++;
            if(temp >= heap_array[j])
                break;
            heap_array[i] = heap_array[j];
            i = j;
            j = 2*j + 1;
        }
        heap_array[i] = temp;
    }
}

bool Heap::findElement(int val)
{
    for(int i=0;i<size;i++)
        if(heap_array[i] == val)
            return true;
    return false;
}
