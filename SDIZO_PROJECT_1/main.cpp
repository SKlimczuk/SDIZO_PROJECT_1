//
//  main.cpp
//  SDIZO_PROJECT_1
//
//  Created by Szymon Klimczuk on 24.02.2018.
//  Copyright © 2018 Szymon Klimczuk. All rights reserved.
//

#include <iostream>

#include "List.hpp"
#include "Array.hpp"

using namespace std;

//prototypy funkcji
void clearScreen();


//------------------
//----F. GLOWNA-----
//------------------
int main(int argc, const char * argv[]) {
    bool condition = true;  //zmienna potrzebna do zapetlenia menu
    int menu = NULL;        //zmienna wyboru
    int arr_val;            //zmienna pomocnicza do przechowywania wartosci wstawianego do tablicy elementu
    int arr_idx;            //zmienna przechowujaca indeks wstawianego/usuwanego/wyszukiwanego elementu
    int list_val;
    int list_idx;
    
    //pomocniczne szablony
    string temp_menu = "1 - dodaj\n2 - usun\n3 - wyszukaj\nWYBOR : ";
    string temp_menu_deeper = "1 - poczatek\n2 - wybierz meiejsce\n3 - koniec\nWYBOR : ";
    
    Array *array = new Array();
    List *list = new List();

    //-----------------------------------------------------------------------------MENU
    do {
        //clearScreen();
        cout << endl << "*** MENU ***" << endl;
        cout << "1 - wczytaj dane z pliku\n2 - wyswietl dane z pliku\n3 - tablica\n4 - lista\n0 - wyjscie\n";
        cout << "WYBOR : ";
        cin >> menu;
        switch (menu) {
            case 1:
            {
                //wczytywanie z pliku tekstowego
                clearScreen();
                string filename;
                cout << "Podaj nazwe pliku (bez rozszerzenia) : ";
                cin >> filename;
                filename += ".txt";
                
                //array->readFromFile(filename);
                //array->printArray();
                list->readFromFile(filename);
                list->printList();
                
            }break;
            case 2:
            {
                //wyswietlanie struktur
                //array->printArray();
                list->printList();
            }break;
            case 3:
            {
                //--------------------TABLICA
                clearScreen();
                cout<<"** TABLICA **"<<endl;
                cout<<temp_menu;
                cin>>menu;
                
                switch (menu) {
                    case 1:
                    {
                        //dodawanie - 3 sytuacje
                        clearScreen();
                        cout<<"* DODAWANIE *"<<endl;
                        cout<<temp_menu_deeper;
                        cin>>menu;
                        switch (menu) {
                            case 1:
                            {
                                //poczatek
                                cout << "Podaj wartosc nowego elementu: ";
                                cin >> arr_val;
                                array->addAtBegin(arr_val);
                                array->printArray();
                            }break;
                            case 2:
                            {
                                //wybrane miejsce
                                cout << "Podaj wartosc nowego elementu: ";
                                cin >> arr_val;
                                cout << "Podaj indeks wstawienia nowego elementu: ";
                                cin >> arr_idx;
                                arr_idx--;
                                array->addAtMiddle(arr_val, arr_idx);
                                array->printArray();
                            }break;
                            case 3:
                            {
                                //koniec
                                cout << "Podaj wartosc nowego elementu: ";
                                cin >> arr_val;
                                array->addAtBottom(arr_val);
                                array->printArray();
                            }break;
                            default:
                                menu = NULL;
                                break;
                        }
                        
                    }break;
                    case 2:
                    {
                        //usuwanie - 3 sytuacje
                        clearScreen();
                        cout<<"* USUWANIE *"<<endl;
                        cout<<temp_menu_deeper;
                        cin>>menu;
                        switch (menu) {
                            case 1:
                            {
                                //poczatek
                                array->deleteFirst();
                                array->printArray();
                            }break;
                            case 2:
                            {
                                //wybrane miejsce
                                cout << "Podaj indeks usuwanego elementu: ";
                                cin >> arr_idx;
                                arr_idx--;
                                array->deleteMiddle(arr_idx);
                                array->printArray();
                            }break;
                            case 3:
                            {
                                //koniec
                                array->deleteLast();
                                array->printArray();
                            }break;
                            default:
                                menu = NULL;
                                break;
                        }
                        
                    }break;
                    case 3:
                    {
                        //wyszukiwanie
                        clearScreen();
                        cout<<"* WYSZUKIWANIE *"<<endl;
                        cout<<"Wyszukaj element: ";
                        cin>>arr_idx;
                        bool findResult = array->findElement(arr_idx);
                        if(findResult)
                            cout << endl << "Tablica zawiera element" << endl;
                        else
                            cout << endl << "Tablica nie zawiera elementu" << endl;
                    }break;
                    default:
                        clearScreen();
                        menu = NULL;
                        break;
                }
            }break;
            case 4:
            {
                //--------------------LISTA
                clearScreen();
                cout<<"** LISTA **"<<endl;
                cout<<temp_menu;
                cin>>menu;
                
                switch (menu) {
                    case 1:
                    {
                        //dodawanie - 3 sytuacje
                        clearScreen();
                        cout<<"* DODAWANIE *"<<endl;
                        cout<<temp_menu_deeper;
                        cin>>menu;
                        switch (menu) {
                            case 1:
                            {
                                //poczatek
                                cout << endl << "Poda wartosc elementu: ";
                                cin >> list_val;
                                list->addAtBegin(list_val);
                                list->printList();
                            }break;
                            case 2:
                            {
                                //wybrane miejsce
                                cout << endl << "Poda wartosc elementu: ";
                                cin >> list_val;
                                cout << endl << "Poda indeks elementu: ";
                                cin >> list_idx;
                                list_idx--;
                                list->addAfterElement(list_val, list_idx);
                                list->printList();

                            }break;
                            case 3:
                            {
                                //koniec
                                cout << endl << "Poda wartosc elementu: ";
                                cin >> list_val;
                                list->addAtBottom(list_val);
                                list->printList();
                            }break;
                            default:
                                menu = NULL;
                                break;
                        }
                        
                    }break;
                    case 2:
                    {
                        //usuwanie - 3 sytuacje
                        clearScreen();
                        cout<<"* USUWANIE *"<<endl;
                        cout<<temp_menu_deeper;
                        cin>>menu;
                        switch (menu) {
                            case 1:
                            {
                                //poczatek
                                list->deleteFirst();
                                list->printList();
                            }break;
                            case 2:
                            {
                                //wybrane miejsce
                                cout << endl << "Poda indeks elementu: ";
                                cin >> list_idx;
                                list_idx--;
                                list->deleteMiddle(list_idx);
                                list->printList();
                            }break;
                            case 3:
                            {
                                //koniec
                                list->deleteLast();
                                list->printList();
                            }break;
                            default:
                                break;
                        }
                        
                    }break;
                    case 3:
                    {
                        //wyszukiwanie
                        clearScreen();
                        cout << "* WYSZUKIWANIE *" << endl;
                        cout << "Wyszukaj element: ";
                        cin >> list_val;
                        bool findResult = list->findElement(list_val);
                        if(findResult)
                            cout << endl << "Lista zawiera element" << endl;
                        else
                            cout << endl << "Lista nie zawiera elementu" << endl;
                    }break;
                    default:
                        clearScreen();
                        menu = NULL;
                        break;
                }
            }break;
            case 0:
            {
                //--------------------WYJSCIE Z PROGRAMU
                clearScreen();
                condition = false;
            }
            default:
                clearScreen();
                menu = NULL;
                break;
        }
    } while(condition);
    
    return 0;
}

void clearScreen()
{
    cout<<string(100, '\n');
}
