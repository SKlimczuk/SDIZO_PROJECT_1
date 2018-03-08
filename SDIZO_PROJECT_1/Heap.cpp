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

void Heap::printHeap()
{
    int el_to_print_idx = 0;
    if(size == 0)
        cout << endl << "Kopiec jest pusty !" << endl;
    else
    {
        
        
    }
}
void Heap::printElement(int idx)
{
    cout << heap_array[idx] << " ";
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

void Heap::removeRoot()
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

void Heap::removeElement(int val)
{
    if(size == 0)
        cout << endl << "Kopiec jest pusty !" << endl;
    else if(!findElement(val))
        cout << endl << "Nie ma takiego elementu !" << endl;
    else
    {
        int idx;
        for(idx=0;idx<size;idx++)
            if(heap_array[idx] == val)
                break;
        //jezeli to ostatni element
        if(idx == size-1)
            size--;
        //jezeli to korzen
        else if(idx == 0)
            removeRoot();
        //nie ostatni i nie korzen
        else
        {
            int last_el_val = heap_array[size-1];
            size--;
            
            int el_to_remove_idx = idx;
            int child_idx = 2*el_to_remove_idx + 1;
            
            while(child_idx < size)
            {
                if(child_idx+1 < size && heap_array[child_idx+1] > heap_array[child_idx])
                    child_idx++;
                if(last_el_val >= heap_array[child_idx])
                    break;
                heap_array[el_to_remove_idx] = heap_array[child_idx];
                el_to_remove_idx = child_idx;
                child_idx = 2*child_idx + 1;
            }
            heap_array[el_to_remove_idx] = last_el_val;
        }
    }
}

bool Heap::findElement(int val)
{
    for(int i=0;i<size;i++)
        if(heap_array[i] == val)
            return true;
    return false;
}
