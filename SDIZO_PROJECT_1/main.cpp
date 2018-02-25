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

int main(int argc, const char * argv[]) {
    bool condition = true;  //zmienna potrzebna do zapetlenia menu
    int menu = NULL;        //zmienna wyboru
    
    //pomocniczne szablony
    string temp_menu = "1 - dodaj\n2 - usun\n3 - wyszukaj\nWYBOR : ";
    string temp_menu_deeper = "1 - poczatek\n2 - wybierz meiejsce\n3 - koniec\nWYBOR : ";

    //-----------------------------------------------------------------------------MENU
    do {
        clearScreen();
        cout<<"*** MENU ***"<<endl;
        cout<<"1 - wczytaj dane z pliku\n2 - tablica\n3 - lista\n0 - wyjscie\n";
        cout<<"WYBOR : ";
        cin>>menu;
        switch (menu) {
            case 1:
            {
                clearScreen();
                string filename;
                cout<<"Podaj nazwe pliku: ";
                cin>>filename;
                filename += ".txt";
                
                
            }break;
            case 2:
            {
                //operacje na tablicy
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
                //operacje na liscie
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
