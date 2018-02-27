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
    
    //pomocniczne szablony
    string temp_menu = "1 - dodaj\n2 - usun\n3 - wyszukaj\nWYBOR : ";
    string temp_menu_deeper = "1 - poczatek\n2 - wybierz meiejsce\n3 - koniec\nWYBOR : ";
    
    Array *array = new Array();

    //-----------------------------------------------------------------------------MENU
    do {
        //clearScreen();
        cout << "*** MENU ***"<<endl;
        cout << "1 - wczytaj i wyswietl dane z pliku\n2 - tablica\n3 - lista\n0 - wyjscie\n";
        cout << "WYBOR : ";
        cin >> menu;
        switch (menu) {
            case 1:
            {
                //wczytywanie z pliku tekstowego
                clearScreen();
                string filename;
                cout << "Podaj nazwe pliku: ";
                cin >> filename;
                filename += ".txt";
                
                array->readFromFile("test.txt");
                array->printArray();
            }break;
            case 2:
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
                        int arr_el;
                        int arr_idx;
                        cout<<"* DODAWANIE *"<<endl;
                        cout<<temp_menu_deeper;
                        cin>>menu;
                        switch (menu) {
                            case 1:
                            {
                                //poczatek
                                cout << "Podaj wartosc nowego elementu: ";
                                cin >> arr_el;
                                array->addAtBegin(arr_el);
                                array->printArray();
                            }break;
                            case 2:
                            {
                                //wybrane miejsce
                                cout << "Podaj wartosc nowego elementu: ";
                                cin >> arr_el;
                                cout << "Podaj miejsce wstawienia: ";
                                cin >> arr_idx;
                                arr_idx--;
                                array->addAtMiddle(arr_el, arr_idx);
                                array->printArray();
                            }break;
                            case 3:
                            {
                                //koniec
                                cout << "Podaj wartosc nowego elementu: ";
                                cin >> arr_el;
                                array->addAtBottom(arr_el);
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
                            }break;
                            case 2:
                            {
                                //wybrane miejsce
                            }break;
                            case 3:
                            {
                                //koniec
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
                        int elementToFind = NULL;
                        cout<<"Wyszukaj element: ";
                        cin>>elementToFind;
                        
                    }break;
                    default:
                        clearScreen();
                        menu = NULL;
                        break;
                }
            }break;
            case 3:
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
                            }break;
                            case 2:
                            {
                                //wybrane miejsce
                            }break;
                            case 3:
                            {
                                //koniec
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
                            }break;
                            case 2:
                            {
                                //wybrane miejsce
                            }break;
                            case 3:
                            {
                                //koniec
                            }break;
                            default:
                                break;
                        }
                        
                    }break;
                    case 3:
                    {
                        //wyszukiwanie
                        clearScreen();
                        cout<<"* WYSZUKIWANIE *"<<endl;
                        int elementToFind = NULL;
                        cout<<"Wyszukaj element: ";
                        cin>>elementToFind;
                        //metoda wyszukujaca element
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
