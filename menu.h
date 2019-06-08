#include <manager.h>

#ifndef MENU_H
#define MENU_H
class Menu:protected Sorter{//Все здешние методы на - самом деле лишь посредники между граф. оболочкой и 
                                //методами управляющего класса "manager"(бывш sorter)
                                //Возможно, вообще удалим этот класс, если в нем не появится нужда
private:
public:
    int add_object(int x, int y, bool *materials, string name = "none", float cost = -1.0);//Метод возвращает индекс, который присуждается ему в manager-е
                                    //И потом по этому индексу он вызывается, и заполняется его material_list
    Plant &GetPlant(int id);
    Container &GetContainer(int id);
    void delete_plant(int id); //Функция, удаляющая завод
    void delete_container(int id); //Функция, удаляющая контейнер
    void Change(int id, int x, int y, bool *materials, string name = "none", float cost = -1.0);//Редакторвание
    bool CheckPassword(string, bool or);//Проверяет пароль
    map<int, Plant> &GetPlantMap();         //Читай след-ю строчку
    map<int, Container> &GetComtainerMap(); //Возможно вместо этих двух методов стоит сделать множество всех id, 
                                                            //и получать объекты через геттеры
                                                            //Подумаем
    void Savetofile(string);
    void Loadfromfile(string);
    

    Menu();
};

#endif // MENU_H
