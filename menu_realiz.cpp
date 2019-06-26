
#include "menu.h"
#include <iostream>
#include <set>
#include <iterator>
#include <fstream>
#include <stdio.h>

void Menu::menu_realiz(){
    bool user_type = 0;
    int g = 1;
    int password;
    int error = 0;
    for (;;) {
        cout << "vvedite 0, esli plant, 1 - esli contaiener" << endl;
        cin >> user_type;
        if(user_type == 0){
            cout << "LOGIN. vvedite parol." << endl;
            cin >> password;
            if(error == check_password(user_type, password) == 0){
                cout << "uspeshno voshli" << endl;
                g = 1;
                break;
            }
            else {
                cout << "neverny parol" << endl;
                break;
            }
        }
        else {
            cout << "LOGIN. vvedite parol." << endl;
            cin >> password;
            if(error == check_password(user_type, password) == 0){
                cout << "uspeshno voshli" << endl;
                g = 2;
                break;
            }
            else {
                cout << "neverny parol" << endl;
                break;
            }
        }
    }

    if(g == 1){
        int choiceMenu = -1;
        cout << "you - plant" << endl;
        for(;;){
            switch(choiceMenu){
            case -1:{
                cout << "=========================================" << endl;
                cout<<"Select operation: "<<endl<<"     0 : Exit"<<endl<<"     1 : Print list on the window"<<endl<<"     2 : Add new plant"<<endl<<\
                      "     3 : Edit information about plant"<<endl << "     4 : Delete plant"<<endl;
                cin>>choiceMenu;
                break;
            }
            case 0:{
                exit(0);
            }
            case 1:{
                cout << "sorryan, ona tok v graphe" << endl;
                choiceMenu = -1;
                break;
            }
            case 2:{
                cout << "id, x, y, met, gl, pap, org, plas, cost" << endl;
                int i, x, y, cost;
                bool met, gl, pap, org, plas;
                cin >> i;
                cin>> x;
                cin >> y;
                cin >> met;
                cin >> gl;
                cin >> pap;
                cin >> org;
                cin >> plas;
                cin >> cost;
                add_plant(i, x, y, met, gl, pap, org, plas, cost);
                choiceMenu = -1;
                break;
            }
            case 3:{
                cout << "id, x, y, met, gl, pap, org, plas, cost" << endl;
                int i, x, y, cost;
                bool met, gl, pap, org, plas;
                cin >> i;
                cin>> x;
                cin >> y;
                cin >> met;
                cin >> gl;
                cin >> pap;
                cin >> org;
                cin >> plas;
                cin >> cost;
                edit_plant(i, x, y, met, gl, pap, org, plas, cost);
                choiceMenu = -1;
                break;
            }
            case 4:{
                cout << "chto udalit' ? vvedite id" << endl;
                int id;
                cin >> id;
                delete_plant(id);
                choiceMenu = -1;
                break;
            }
            default:{
                cout<<"Sorry, this operation does not exist. Please, select operation again.";
                choiceMenu = -1;
                break;
            }
            }
        }
    }

    if(g == 2){
        int choiceMenu = -1;
        cout << "you - container" << endl;
        for(;;){
            switch(choiceMenu){
            case -1:{
                cout << "=========================================" << endl;
                cout<<"Select operation: "<<endl<<"     0 : Exit"<<endl<<"     1 : Print list on the window"<<endl<<"     2 : Add new container"<<endl<<\
                      "     3 : Edit information about container"<<endl << "     4 : Delete container"<<endl;
                cin>>choiceMenu;
                break;
            }
            case 0:{
                exit(0);
            }
            case 1:{
                cout << "sorryan, ona tok v graphe" << endl;
                choiceMenu = -1;
                break;
            }
            case 2:{
                cout << "id, x, y, met, gl, pap, org, plas" << endl;
                int i, x, y;
                bool met, gl, pap, org, plas;
                cin >> i;
                cin>> x;
                cin >> y;
                cin >> met;
                cin >> gl;
                cin >> pap;
                cin >> org;
                cin >> plas;
                add_container(i, x, y, met, gl, pap, org, plas);
                choiceMenu = -1;
                break;
            }
            case 3:{
                cout << "id, x, y, met, gl, pap, org, plas" << endl;
                int i, x, y;
                bool met, gl, pap, org, plas;
                cin >> i;
                cin>> x;
                cin >> y;
                cin >> met;
                cin >> gl;
                cin >> pap;
                cin >> org;
                cin >> plas;
                edit_container(i, x, y, met, gl, pap, org, plas);
                choiceMenu = -1;
                break;
            }
            case 4:{
                cout << "chto udalit' ? vvedite id" << endl;
                int id;
                cin >> id;
                delete_container(id);
                choiceMenu = -1;
                break;
            }
            default:{
                cout<<"Sorry, this operation does not exist. Please, select operation again.";
                choiceMenu = -1;
                break;
            }
            }
        }
    }
}
