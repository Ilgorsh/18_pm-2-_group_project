/*!
\file menu.cpp
\brief Меню
*/
#include "menu.h"
#include <iostream>
#include <set>
#include <iterator>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

int Menu::add_plant(int ID, int x_coord, int y_coord, bool metal, bool glass, bool paper, bool organic, bool plastic, int cost){
    cout<<"Enter container`s name"<<endl;
    set<Plant> _add_Plant = read_Plants();
    Plant add_New;
   // char* s1;
     //s1=nullptr;
    int error_State = 0; //Если нет ошибок
//    cin>>s1;
//    add_New.setname(s1);
    add_New.setid(ID);
    if(ID < 0){
        error_State = 1;
        return error_State; // Если некорректный ID
    }

    add_New.setx(x_coord);
    add_New.sety(y_coord);
    add_New.setmat_metal(metal);
    add_New.setmat_glass(glass);
    add_New.setmat_paper(paper);
    add_New.setmat_organic(organic);
    add_New.setmat_plastic(plastic);

    add_New.set_distance_cost(cost);
    if(cost < 0){
        error_State = 2; //Если некорректная цена
        return error_State;
    }

    _add_Plant.insert(add_New);
    print_in_file_plant(_add_Plant);
    return error_State; //Если завершилась без ошибок, ретернит 0
}
/*!
     \brief Добавление контейнеров и информации о них
 */
int Menu::add_container(int ID, int x_coord, int y_coord, bool metal, bool glass, bool paper, bool organic, bool plastic){
    set<Container> _add_Container = read_Containers();
    Container add_New;
    //char* s1;
    //s1=nullptr;
    //cin>>s1;
    //add_New.setname(s1);
    int error_State = 0; //Если нет ошибок

    add_New.setid(ID);
    if(ID < 0){
        error_State = 1;
        return error_State; // Если некорректный ID
    }

    add_New.setx(x_coord);
    add_New.sety(y_coord);
    add_New.setmat_metal(metal);
    add_New.setmat_glass(glass);
    add_New.setmat_paper(paper);
    add_New.setmat_organic(organic);
    add_New.setmat_plastic(plastic);

    _add_Container.insert(add_New);
    print_in_file_container(_add_Container);
    return error_State; //Если без ошибок, ретернит 0
}
/*!
     \brief Удаление завода
 */
int Menu::delete_plant(int id){
    set<Plant> plants_set = read_Plants();
    Plant del;
    bool found = 0;
    set<Plant>::iterator it = plants_set.begin();
    for(int i = 0; i < id; i++){
        del = *it;
        if(del.getid() == id){
            found = 1;
            break;
        }
        it++;
    }

    if(found == 0){
        return found = 0;
    }

    plants_set.erase(it);
    print_in_file_plant(plants_set);
    return found = 1; // если завод был найден и успешно удален
}
/*!
     \brief Удаление контейнера
 */
int Menu::delete_container(int id){
    set<Container> containers_set = read_Containers();
    Container del;
    bool found = 0;
    set<Container>::iterator it = containers_set.begin();
    for(int i = 0; i < id; i++){
        del = *it;
        if(del.getid() == id){
            found = 1;
            break;
        }
        it++;
    }

    if(found == 0){
        return found = 0;
    }

    containers_set.erase(it);
    print_in_file_container(containers_set);
    return found = 1; // если завод был найден и успешно удален
}
/*!
     \brief Редактирование информации о заводе
 */
int Menu::edit_plant(int ID, int x_coord, int y_coord, bool metal, bool glass, bool paper, bool organic, bool plastic, int cost){
    set<Plant> edit_plant = read_Plants();
    Plant edit;
    bool found = false;

    for(set<Plant>::iterator it = edit_plant.begin(); it != edit_plant.end(); it++){
        edit = *it;
        if(edit.getid() == ID){
            edit_plant.erase(it);
            found = 1;
            break;
        }
    }

    if(found){
        edit.setid(ID);
        if(edit.getid() < 0){
            edit_plant.clear();
            return 1; // некорректный айди
        }

        edit.setx(x_coord);
        edit.sety(y_coord);
        edit.setmat_metal(metal);
        edit.setmat_glass(glass);
        edit.setmat_paper(paper);
        edit.setmat_organic(organic);
        edit.setmat_plastic(plastic);
        edit.set_distance_cost(cost);
        if(cost < 0){
            edit_plant.clear();
            return 2; // некорректная цена
        }
    }
    edit_plant.insert(edit);
    print_in_file_plant(edit_plant);
    return 0;//если без ошибочек
}
/*!
     \brief Редактирование информации о контейнере
 */
int Menu::edit_container(int ID, int x_coord, int y_coord, bool metal, bool glass, bool paper, bool organic, bool plastic){
    set<Container> edit_container = read_Containers();
    Container edit;
    bool found = false;
    for(set<Container>::iterator it = edit_container.begin(); it != edit_container.end(); it++){
        edit = *it;
        if(edit.getid() == ID){
            edit_container.erase(it);
            found = 1;
            break;
        }
    }

    if(found){
        edit.setid(ID);
        if(edit.getid() < 0){
            edit_container.clear();
            return 1; // некорректный айди
        }

        edit.setx(x_coord);
        edit.sety(y_coord);
        edit.setmat_metal(metal);
        edit.setmat_glass(glass);
        edit.setmat_paper(paper);
        edit.setmat_organic(organic);
        edit.setmat_plastic(plastic);
    }
    edit_container.insert(edit);
    print_in_file_container(edit_container);
    return 0;//если без ошибочек
}
/*!
     \brief  Запись в файл информации о заводах
 */
void Menu::print_in_file_plant(set<Plant> plants){
    ofstream base;
    base.open("Plants.bin", ofstream::binary);
    if(!base.is_open()){
        cout << "Error opening file!";
        exit(0);
    }

    Plant in;
    for(set<Plant>::iterator it = plants.begin(); it != plants.end(); it++){
        in = *it;
        int i = in.getid();
        base.write(reinterpret_cast<char*>(&i), sizeof(int));
        int x = in.getcoordx();
        base.write(reinterpret_cast<char*>(&x), sizeof (int));
        int y = in.getcoordy();
        base.write(reinterpret_cast<char*>(&y), sizeof (int));
        bool m = in.getmetal();
        base.write(reinterpret_cast<char*>(&m), sizeof (bool));
        bool g = in.getglass();
        base.write(reinterpret_cast<char*>(&g), sizeof (bool));
        bool p = in.getpaper();
        base.write(reinterpret_cast<char*>(&p), sizeof (bool));
        bool o = in.getorganic();
        base.write(reinterpret_cast<char*>(&o), sizeof (bool));
        bool pl = in.getplastic();
        base.write(reinterpret_cast<char*>(&pl), sizeof (bool));
        int c = in.get_distance_cost();
        base.write(reinterpret_cast<char*>(&c), sizeof (int));
       // char* s = in.getname();
        //base.write(s, sizeof (s));

    }
    plants.clear();
    base.close();
}
/*!
     \brief Запись в файл информации о контейнерах
 */
void Menu::print_in_file_container(set<Container> containers){
    ofstream base("Containers.bin", ofstream::binary); //?

    if(!base.is_open()){
        cout << "Error opening file!";
        exit(0);
    }

    Container in;
    for(set<Container>::iterator it = containers.begin(); it != containers.end(); it++){
        in = *it;
        int i = in.getid();
        base.write(reinterpret_cast<char*>(&i), sizeof(int));
        int x = in.getcoordx();
        base.write(reinterpret_cast<char*>(&x), sizeof (int));
        int y = in.getcoordy();
        base.write(reinterpret_cast<char*>(&y), sizeof (int));
        bool m = in.getmetal();
        base.write(reinterpret_cast<char*>(&m), sizeof (bool));
        bool g = in.getglass();
        base.write(reinterpret_cast<char*>(&g), sizeof (bool));
        bool p = in.getpaper();
        base.write(reinterpret_cast<char*>(&p), sizeof (bool));
        bool o = in.getorganic();
        base.write(reinterpret_cast<char*>(&o), sizeof (bool));
        bool pl = in.getplastic();
        base.write(reinterpret_cast<char*>(&pl), sizeof (bool));
       // char* s = in.getname();
        //base.write(s, sizeof (s));
    }
    containers.clear();
    base.close();
}
/*!
     \brief Возвращает результат работы сортировщика, завод и подобраннные для него контейнеры
 */
map<Plant, set<Container>> Menu::get_map_plant_to_container(){
    return remap(Map(read_Containers(), read_Plants()));
}
/*!
     \brief Возвращает результат работы сортировщика, контейнер и подобраннные для него заводы
 */
map<Container, set<Plant>> Menu::get_map_container_to_plant(){
    return Map(read_Containers(), read_Plants());
}
/*!
     \brief Вход в систему
 */
int Menu::check_password(bool user_state, int pass){
    ifstream users(":/f/users.txt");
    int plant_pass, container_pass;
    users >> plant_pass >> container_pass;
    //0 - plant; 1 - container;
    if(user_state == 0){
        if(plant_pass == pass){
            return 0; //успешно вошел
        }
        else {
            return 1; //неверный пароль
        }
    }
    else {
        if(container_pass == pass){
            return 0; //успешно вошел
        }
        else {
            return 1; //неверный пароль
        }
    }
    users.close();
}
