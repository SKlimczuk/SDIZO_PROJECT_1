//
//  main.cpp
//  SDIZO_PROJECT_1
//
//  Created by Szymon Klimczuk on 24.02.2018.
//  Copyright © 2018 Szymon Klimczuk. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    bool condition = true;
    int menu = NULL;
    
    string temp_menu = "1 - dodaj\n2 - usun\n3 - wyszukaj\n";
    string temp_menu_deeper = "1 - poczatek\n2 - losowe meiejsce\n3 - koniec\n";
    
    cout<<"*** MENU ***"<<endl;
    cout<<"1 - wczytaj dane z pliku\n2 - tablica\n3 - lista\n0 - wyjscie\n";
    cout<<"WYBOR : ";
    cin>>menu;
    
    while(condition == true)
    {
        switch (menu) {
            case 1:
            {
                string filename;
                cout<<"Podaj nazwe pliku: ";
                cin>>filename;
                filename += ".txt";
                
                
            }break;
            case 2:
            {
                
                
            }break;
            case 3:
            {
                
            }break;
            case 0:
            {
                return 0;
            }
            default:
                break;
        }
    }
    return 0;
}
