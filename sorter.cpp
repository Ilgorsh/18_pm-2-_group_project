#include "sorter.h"
#include <fstream>
#include <set>
#include "container.h"
#include "plant.h"
#include <algorithm>

using namespace std;

Sorter::Sorter()
{

}

set<Container> Sorter::read_Containers()
{
    set<Container> Containers_list;
    int a;
    bool b;
    Container cont;
    ifstream in;
    in.open("Containers.bin");
    if(in.is_open())
        cout<<"File is open"<<endl;
    else
    {
        cout<<"Can`t open the file"<<endl;
    }
    while(in){
        in.read(reinterpret_cast<char*>(&a),sizeof(int));
        cont.setid(a);
        in.read(reinterpret_cast<char*>(&a),sizeof(int));
        cont.setx(a);
        in.read(reinterpret_cast<char*>(&a),sizeof(int));
        cont.sety(a);
        in.read(reinterpret_cast<char*>(&b),sizeof(bool));
        cont.setmat_metal(b);
        in.read(reinterpret_cast<char*>(&b),sizeof(bool));
        cont.setmat_glass(b);
        in.read(reinterpret_cast<char*>(&b),sizeof(bool));
        cont.setmat_paper(b);
        in.read(reinterpret_cast<char*>(&b),sizeof(bool));
        cont.setmat_organic(b);
        in.read(reinterpret_cast<char*>(&b),sizeof(bool));
        cont.setmat_plastic(b);
        Containers_list.insert(cont);
        cont.set_encounters(0);
    }
    return(Containers_list);
}
double Sorter::cost(Container container,Plant plant)
{
    double cost;
    cost=sqrt(pow((plant.getcoordx()-container.getcoordx()),2)+pow((plant.getcoordy()-container.getcoordy()),2))*(plant.get_distance_cost());
    return(cost);
}
set<Plant> Sorter::read_Plants()
{
    set<Plant> Plants_list;
    int a;
    bool b;
    Plant plant;
    ifstream in;
    in.open("Containers.bin");
    if(in.is_open())
        cout<<"File is open"<<endl;
    else
    {
        cout<<"Can`t open the file"<<endl;
    }
    while(in){
        in.read(reinterpret_cast<char*>(&a),sizeof(int));
        plant.setid(a);
        in.read(reinterpret_cast<char*>(&a),sizeof(int));
        plant.setx(a);
        in.read(reinterpret_cast<char*>(&a),sizeof(int));
        plant.sety(a);
        in.read(reinterpret_cast<char*>(&b),sizeof(bool));
        plant.setmat_metal(b);
        in.read(reinterpret_cast<char*>(&b),sizeof(bool));
        plant.setmat_glass(b);
        in.read(reinterpret_cast<char*>(&b),sizeof(bool));
        plant.setmat_paper(b);
        in.read(reinterpret_cast<char*>(&b),sizeof(bool));
        plant.setmat_organic(b);
        in.read(reinterpret_cast<char*>(&b),sizeof(bool));
        plant.setmat_plastic(b);
        in.read(reinterpret_cast<char*>(&a),sizeof(int));
        plant.set_distance_cost(a);
        Plants_list.insert(plant);
    }
    return(Plants_list);
}



void Sorter()
{
        set<Container> Containers ;
        Containers = Sorter::read_Containers();
        set<Plant> Plants;
        Plants = Sorter::read_Plants();
        map<Container,set<Plant>> result; //итоговый мэп
        for (set<Container>::iterator iter = Containers.begin();iter!=Containers.end();iter++)
        {
            auto i = *iter;
            int x = i.get_number_of_types();
            switch (x)//переключаемся в зависимости от числа типов мусора
            {
                case(1):
            {
                set<Plant> result_plants;
                Plant one;//
                double cost_1;

                cost_1 = INFINITY;

                for (set<Plant>::iterator iter1 = Plants.begin();iter1 != Plants.end();iter1++)//крутим контейнеры
                {
                    auto i1 = *iter1;
                    //если стоимость перевозки меньше чем текущая для 1 и  совпадают 1
                    if((Sorter::cost(i,i1)<cost_1)&&(((i1.getglass()==i.getglass())+(i1.getmetal()==i.getmetal())+(i1.getpaper()==i.getpaper())+(i1.getorganic()==i.getorganic())+(i1.getplastic()==i.getplastic()))==1))
                    {
                        cost_1=Sorter::cost(i,i1);//перепишем минимум
                        one=i1;
                    }//если стоимость перевозки меньше чем текущая для 2 и совпадает  2 или более типов

                }
                result_plants.insert(one);
                result.insert(pair<Container,set<Plant>>(i,result_plants));//вносим всё в результат
                break;
            }
                case(2):
            {
                    double result_cost; //результативная стоимость
                    set<Plant> result_plants;
                    Plant duo;
                    Plant one_1,one_2;
                    double cost_2, cost_1_1, cost_1_2;
                    cost_2 = INFINITY;
                    cost_1_1 = INFINITY;
                    cost_1_2 = INFINITY;
                    for (set<Plant>::iterator iter1 = Plants.begin();iter1 != Plants.end();iter1++)//крутим контейнеры
                    {
                        auto i1 = *iter1;
                        //если стоимость перевозки меньше чем текущая для 2 и  совпадают 2 или более типа
                        if((Sorter::cost(i,i1)<cost_2)&&(((i1.getglass()==i.getglass())+(i1.getmetal()==i.getmetal())+(i1.getpaper()==i.getpaper())+(i1.getorganic()==i.getorganic())+(i1.getplastic()==i.getplastic()))>=2))
                        {
                            cost_2=Sorter::cost(i,i1);//перепишем минимум
                            duo=i1;//сохраним копию
                        }//если стоимость перевозки меньше чем текущая для 2 и совпадает  2 или более типов

                        //если стоимость перевозки меньше чем текущая для 1 и совпадает только 1 тип или более
                        if((Sorter::cost(i,i1)<cost_1_1)&&((i1.getglass()==i.getglass())+(i1.getmetal()==i.getmetal())+(i1.getpaper()==i.getpaper())+(i1.getorganic()==i.getorganic())+(i1.getplastic()==i.getplastic()))>=1)
                        {
                            cost_1_1=Sorter::cost(i,i1);//перепишем минимум
                            one_1 = i1;//сохраним копию
                        }
                    }
                    //ищем "довесок" для 1
                    for (set<Plant>::iterator iter1 = Plants.begin();iter1 != Plants.end();iter1++)
                    {
                        auto i1=*iter1;
                        //если  "довесок" меньше текущего и число совпаденией 1 или больше
                        if((Sorter::cost(i,i1)<cost_1_2)&&((i1.getglass()==i.getglass())+(i1.getmetal()==i.getmetal())+(i1.getpaper()==i.getpaper())+(i1.getorganic()==i.getorganic())+(i1.getplastic()==i.getplastic()))>=1)
                        {
                            //если нет совпадений с сохраненной 1
                            if((i1.getglass()==one_1.getglass())&&(i1.getmetal()==one_1.getmetal())&&(i1.getpaper()==one_1.getpaper())&&(i1.getorganic()==one_1.getorganic())&&(i1.getplastic()==one_1.getplastic()))
                            {
                                cost_1_2=Sorter::cost(i,i1);//перепишем минимум
                                one_2=i1;//сохраним копию
                            }
                        }
                    }
                    result_cost=min(cost_2,cost_1_1+cost_1_2);//ищем минимальную итоговую стоимомть
                    //заполняем сеты заводов
                    if(result_cost==cost_2)
                    {
                        result_plants.insert(duo);
                    }
                    else if (result_cost==cost_1_1+cost_1_2)
                    {
                        result_plants.insert(one_1);
                        result_plants.insert(one_2);
                    }

                    result.insert(pair<Container,set<Plant>>(i,result_plants));//вносим всё в результат
                    break;
                }
                case(3):
                {
                    double result_cost; //результативная стоимость
                    set<Plant> result_plants;
                    Plant trio;
                    Plant duo, duo_1;// завод (техническая переменная)
                    Plant one_1, one_2, one_3;//
                    double cost_3 , cost_2, cost_1_1, cost_1_2, cost_1_3, cost_2_1; //стоимости 3 2 и 1(три минимума для 1) и стоимость "довеска" к 2
                    cost_3=INFINITY;
                    cost_2 = INFINITY;
                    cost_1_1 = INFINITY;
                    cost_1_2 = INFINITY;
                    cost_1_3 = INFINITY;
                    cost_2_1 = INFINITY;
                    for (set<Plant>::iterator iter1 = Plants.begin();iter1 != Plants.end();iter1++)//крутим контейнеры
                    {
                        auto i1 = *iter1;
                        //если стоимость перевозки меньше чем текущая для 3 и  совпадают 3 или более типа
                        if((Sorter::cost(i,i1)<cost_3)&&(((i1.getglass()==i.getglass())+(i1.getmetal()==i.getmetal())+(i1.getpaper()==i.getpaper())+(i1.getorganic()==i.getorganic())+(i1.getplastic()==i.getplastic()))>=3))
                        {
                            cost_3=Sorter::cost(i,i1);//перепишем минимум
                            trio=i1;//сохраним копию
                        }//если стоимость перевозки меньше чем текущая для 2 и совпадает  2 или более типов
                        if((Sorter::cost(i,i1)<cost_2)&&((i1.getglass()==i.getglass())+(i1.getmetal()==i.getmetal())+(i1.getpaper()==i.getpaper())+(i1.getorganic()==i.getorganic())+(i1.getplastic()==i.getplastic()))>=2)
                        {
                            cost_2=Sorter::cost(i,i1);//перепишем минимум
                            duo = i1;//сохраним копию
                        }//если стоимость перевозки меньше чем текущая для 1 и совпадает только 1 тип или более
                        if((Sorter::cost(i,i1)<cost_1_1)&&((i1.getglass()==i.getglass())+(i1.getmetal()==i.getmetal())+(i1.getpaper()==i.getpaper())+(i1.getorganic()==i.getorganic())+(i1.getplastic()==i.getplastic()))>=1)
                        {
                            cost_1_1=Sorter::cost(i,i1);//перепишем минимум
                            one_1 = i1;//сохраним копию
                        }
                    }
                    //ищем "довесок" для 2
                    for (set<Plant>::iterator iter1 = Plants.begin();iter1 != Plants.end();iter1++)
                    {
                        auto i1=*iter1;
                        //если  "довесок" меньше текущего и число совпаденией 1 или больше
                        if((Sorter::cost(i,i1)<cost_2_1)&&((i1.getglass()==i.getglass())+(i1.getmetal()==i.getmetal())+(i1.getpaper()==i.getpaper())+(i1.getorganic()==i.getorganic())+(i1.getplastic()==i.getplastic()))>=1)
                        {
                            //если нет совпадений с сохраненной двойкой
                            if((i1.getglass()==duo.getglass())&&(i1.getmetal()==duo.getmetal())&&(i1.getpaper()==duo.getpaper())&&(i1.getorganic()==duo.getorganic())&&(i1.getplastic()==duo.getplastic()))
                            {
                                cost_2_1=Sorter::cost(i,i1);//перепишем минимум
                                duo_1=i1;//сохраним копию
                            }
                        }
                    }
                    //ищем ещё 1 для 1
                    for (set<Plant>::iterator iter1 = Plants.begin();iter1 != Plants.end();iter1++)
                    {
                        auto i1=*iter1;
                        //если совпадает 1 или более тип с контейнером
                        if(((i1.getglass()==i.getglass())+(i1.getmetal()==i.getmetal())+(i1.getpaper()==i.getpaper())+(i1.getorganic()==i.getorganic())+(i1.getplastic()==i.getplastic()))>=1)
                        {
                            //если не совпадает с сохранённой 1 и стоимость меньше текущей
                            if((Sorter::cost(i,i1)<cost_1_2)&&!((i1.getglass()==one_1.getglass())&&(i1.getmetal()==one_1.getmetal())&&(i1.getpaper()==one_1.getpaper())&&(i1.getorganic()==one_1.getorganic())&&(i1.getplastic()==one_1.getplastic())))
                            {
                                cost_1_2=Sorter::cost(i,i1);//перепишем минимум
                                one_2 = i1;//сохраним копию
                            }
                        }
                    }
                    //ищем вторую 1 для 1
                    for (set<Plant>::iterator iter1 = Plants.begin();iter1 != Plants.end();iter1++)
                    {
                        auto i1=*iter1;
                        //если совпадает 1 или более тип с контейнером
                        if(((i1.getglass()==i.getglass())+(i1.getmetal()==i.getmetal())+(i1.getpaper()==i.getpaper())+(i1.getorganic()==i.getorganic())+(i1.getplastic()==i.getplastic()))>=1)
                        {
                            //если не совпадает с сохранёнными двумя 1 и стоимость меньше текущей
                            if((Sorter::cost(i,i1)<cost_1_3)&&!((i1.getglass()==one_1.getglass())&&(i1.getmetal()==one_1.getmetal())&&(i1.getpaper()==one_1.getpaper())&&(i1.getorganic()==one_1.getorganic())&&(i1.getplastic()==one_1.getplastic()))&&!((i1.getglass()==one_2.getglass())&&(i1.getmetal()==one_2.getmetal())&&(i1.getpaper()==one_2.getpaper())&&(i1.getorganic()==one_2.getorganic())&&(i1.getplastic()==one_2.getplastic())))
                            {
                                cost_1_3=Sorter::cost(i,i1);//перепишем минимум
                                one_3=i1;//созраним копию
                            }
                        }
                    }
                    result_cost=min(cost_2,cost_2+cost_2_1);//ищем минимальную итоговую стоимомть
                    result_cost=min(cost_1_1+cost_1_2+cost_1_3,result_cost);
                    //заполняем сеты заводов
                    if(result_cost==cost_3)
                    {
                        result_plants.insert(trio);
                    }
                    else if (result_cost==cost_2+cost_2_1)
                    {
                        result_plants.insert(duo);
                        result_plants.insert(duo_1);
                    }
                    else
                    {
                        result_plants.insert(one_1);
                        result_plants.insert(one_2);
                        result_plants.insert(one_3);
                    }
                    result.insert(pair<Container,set<Plant>>(i,result_plants));//вносим всё в результат
                    break;
                }
                case(4):
            {
        double result_cost; //результативная стоимость
        set<Plant> result_plants;
        Plant quadro;
        Plant trio,trio_1;
        Plant duo, duo_2_1,duo_1_1,duo_1_2 ;// завод (техническая переменная)
        Plant one_1, one_2, one_3,one_4;//
        double cost_4 , cost_3, cost_3_1, cost_2_2,cost_2_1, cost_2_1_1, cost_22_1_1,cost_1,cost_1_1_1_1,cost2_1_1_1_1,cost3_1_1_1_1; //стоимости 3 2 и 1(три минимума для 1) и стоимость "довеска" к 2
        cost_4=INFINITY;
        cost_3 = INFINITY;
        cost_2_2 = INFINITY;
        cost_2_1= INFINITY;
        cost_1   = INFINITY;
        cost_2_1_1 = INFINITY;
        cost_22_1_1= INFINITY;
        cost_1_1_1_1 = INFINITY;
        for (set<Plant>::iterator iter1 = Plants.begin();iter1 != Plants.end();iter1++)//крутим контейнеры
        {
            auto i1 = *iter1;
            //если стоимость перевозки меньше чем текущая для 4 и  совпадают 4 или более типа
            if((Sorter::cost(i,i1)<cost_4)&&(((i1.getglass()==i.getglass())+(i1.getmetal()==i.getmetal())+(i1.getpaper()==i.getpaper())+(i1.getorganic()==i.getorganic())+(i1.getplastic()==i.getplastic()))>=4))
            {
                cost_4=Sorter::cost(i,i1);//перепишем минимум
                quadro=i1;//сохраним копию
            }//если стоимость перевозки меньше чем текущая для 2 и совпадает  2 или более типов
            if((Sorter::cost(i,i1)<cost_3)&&((i1.getglass()==i.getglass())+(i1.getmetal()==i.getmetal())+(i1.getpaper()==i.getpaper())+(i1.getorganic()==i.getorganic())+(i1.getplastic()==i.getplastic()))>=3)
            {
                cost_3=Sorter::cost(i,i1);//перепишем минимум
                trio = i1;//сохраним копию
            }//если стоимость перевозки меньше чем текущая для 1 и совпадает только 1 тип или более
            if((Sorter::cost(i,i1)<cost_2_2)&&((i1.getglass()==i.getglass())+(i1.getmetal()==i.getmetal())+(i1.getpaper()==i.getpaper())+(i1.getorganic()==i.getorganic())+(i1.getplastic()==i.getplastic()))>=2)
            {
                cost_2_2=Sorter::cost(i,i1);//перепишем минимум
                duo = i1;//сохраним копию
            }
            if((Sorter::cost(i,i1)<cost_1)&&((i1.getglass()==i.getglass())+(i1.getmetal()==i.getmetal())+(i1.getpaper()==i.getpaper())+(i1.getorganic()==i.getorganic())+(i1.getplastic()==i.getplastic()))>=1)
            {
                cost_1=Sorter::cost(i,i1);//перепишем минимум
                one_1 = i1;//сохраним копию
            }

        }
        //ищем "довесок" для 3
        for (set<Plant>::iterator iter1 = Plants.begin();iter1 != Plants.end();iter1++)
        {
            auto i1=*iter1;
            //если  "довесок" меньше текущего и число совпаденией 1 или больше
            if((Sorter::cost(i,i1)<cost_3_1)&&((i1.getglass()==i.getglass())+(i1.getmetal()==i.getmetal())+(i1.getpaper()==i.getpaper())+(i1.getorganic()==i.getorganic())+(i1.getplastic()==i.getplastic()))>=1)
            {
                //если нет совпадений с сохраненной тройкой
                // Здесь не должно перед скобками быть?
                if((i1.getglass()==trio.getglass())&&(i1.getmetal()==trio.getmetal())&&(i1.getpaper()==trio.getpaper())&&(i1.getorganic()==trio.getorganic())&&(i1.getplastic()==trio.getplastic()))
                {
                    cost_3_1=Sorter::cost(i,i1);//перепишем минимум
                    trio_1=i1;//сохраним копию
                }
            }
        }
        //ищем для 2
        for (set<Plant>::iterator iter1 = Plants.begin();iter1 != Plants.end();iter1++)
        {
            auto i1=*iter1;
            //если совпадает 2 или более тип с контейнером
            if(((i1.getglass()==i.getglass())+(i1.getmetal()==i.getmetal())+(i1.getpaper()==i.getpaper())+(i1.getorganic()==i.getorganic())+(i1.getplastic()==i.getplastic()))>=2)
            {
                //если не совпадает с сохранённой 2 и стоимость меньше текущей
                if((Sorter::cost(i,i1)<cost_2_1)&&!((i1.getglass()==duo.getglass())&&(i1.getmetal()==duo.getmetal())&&(i1.getpaper()==duo.getpaper())&&(i1.getorganic()==duo.getorganic())&&(i1.getplastic()==duo.getplastic())))
                {
                    cost_2_1=Sorter::cost(i,i1);//перепишем минимум
                    duo_2_1 = i1;//сохраним копию
                }
            }
        }

        // первый для 2 1 1

        for (set<Plant>::iterator iter1 = Plants.begin();iter1 != Plants.end();iter1++)
        {
            auto i1=*iter1;
            //если совпадает 1 или более тип с контейнером
            if(((i1.getglass()==i.getglass())+(i1.getmetal()==i.getmetal())+(i1.getpaper()==i.getpaper())+(i1.getorganic()==i.getorganic())+(i1.getplastic()==i.getplastic()))>=1)
            {
                //если не совпадает с сохранённой 2 и 2 стоимость меньше текущей
                if((Sorter::cost(i,i1)<cost_2_1_1)&&!((i1.getglass()==duo.getglass())&&(i1.getmetal()==duo.getmetal())&&(i1.getpaper()==duo.getpaper())&&(i1.getorganic()==duo.getorganic())&&(i1.getplastic()==duo.getplastic())))
                {
                    cost_2_1_1=Sorter::cost(i,i1);//перепишем минимум
                    duo_1_1=i1;//созраним копию
                }
            }
        }
        //ищем вторую к 2 1 и 1
        for (set<Plant>::iterator iter1 = Plants.begin();iter1 != Plants.end();iter1++)
        {
            auto i1=*iter1;
            //если совпадает 1 или более тип с контейнером
            if(((i1.getglass()==i.getglass())+(i1.getmetal()==i.getmetal())+(i1.getpaper()==i.getpaper())+(i1.getorganic()==i.getorganic())+(i1.getplastic()==i.getplastic()))>=1)
            {
                //если не совпадает с сохранённой 2 и стоимость меньше текущей
                if((Sorter::cost(i,i1)<cost_22_1_1)&&!(((i1.getglass()==duo.getglass())&&(i1.getmetal()==duo.getmetal())&&(i1.getpaper()==duo.getpaper())&&(i1.getorganic()==duo.getorganic())&&(i1.getplastic()==duo.getplastic()))&&!(((i1.getglass()==duo_1_1.getglass())&&(i1.getmetal()==duo_1_1.getmetal())&&(i1.getpaper()==duo_1_1.getpaper())&&(i1.getorganic()==duo_1_1.getorganic())&&(i1.getplastic()==duo_1_1.getplastic())))))
                {
                    cost_22_1_1=Sorter::cost(i,i1);//перепишем минимум
                    duo_1_2=i1;//созраним копию
                }
            }
        }


        // для 1 1 1 1
        for (set<Plant>::iterator iter1 = Plants.begin();iter1 != Plants.end();iter1++)
        {
            auto i1=*iter1;
            //если совпадает 1 или более тип с контейнером
            if(((i1.getglass()==i.getglass())+(i1.getmetal()==i.getmetal())+(i1.getpaper()==i.getpaper())+(i1.getorganic()==i.getorganic())+(i1.getplastic()==i.getplastic()))>=1)
            {

                if((Sorter::cost(i,i1)<cost_1_1_1_1)&&!((i1.getglass()==one_1.getglass())&&(i1.getmetal()==one_1.getmetal())&&(i1.getpaper()==one_1.getpaper())&&(i1.getorganic()==one_1.getorganic())&&(i1.getplastic()==one_1.getplastic())))
                {
                    cost_1_1_1_1=Sorter::cost(i,i1);//перепишем минимум
                    one_2=i1;//созраним копию
                }
            }
        }
        //ищем вторую к 2 1 и 1
        for (set<Plant>::iterator iter1 = Plants.begin();iter1 != Plants.end();iter1++)
        {
            auto i1=*iter1;
            //если совпадает 1 или более тип с контейнером
            if(((i1.getglass()==i.getglass())+(i1.getmetal()==i.getmetal())+(i1.getpaper()==i.getpaper())+(i1.getorganic()==i.getorganic())+(i1.getplastic()==i.getplastic()))>=1)
            {
                //если не совпадает с сохранённой 2 и стоимость меньше текущей
                if((Sorter::cost(i,i1)<cost2_1_1_1_1)&&!(((i1.getglass()==one_1.getglass())&&(i1.getmetal()==one_1.getmetal())&&(i1.getpaper()==one_1.getpaper())&&(i1.getorganic()==one_1.getorganic())&&(i1.getplastic()==one_1.getplastic()))&&!(((i1.getglass()==one_2.getglass())&&(i1.getmetal()==one_2.getmetal())&&(i1.getpaper()==one_2.getpaper())&&(i1.getorganic()==one_2.getorganic())&&(i1.getplastic()==one_2.getplastic())))))
                {
                    cost2_1_1_1_1=Sorter::cost(i,i1);//перепишем минимум
                    one_3=i1;//созраним копию
                }
            }
        }

        for (set<Plant>::iterator iter1 = Plants.begin();iter1 != Plants.end();iter1++)
        {
            auto i1=*iter1;
            //если совпадает 1 или более тип с контейнером
            if(((i1.getglass()==i.getglass())+(i1.getmetal()==i.getmetal())+(i1.getpaper()==i.getpaper())+(i1.getorganic()==i.getorganic())+(i1.getplastic()==i.getplastic()))>=1)
            {
                //если не совпадает с сохранённой 2 и стоимость меньше текущей
                if((Sorter::cost(i,i1)<cost3_1_1_1_1)&&!(((i1.getglass()==one_1.getglass())&&(i1.getmetal()==one_1.getmetal())&&(i1.getpaper()==one_1.getpaper())&&(i1.getorganic()==one_1.getorganic())&&(i1.getplastic()==one_1.getplastic()))&&!(((i1.getglass()==one_3.getglass())&&(i1.getmetal()==one_3.getmetal())&&(i1.getpaper()==one_3.getpaper())&&(i1.getorganic()==one_3.getorganic())&&(i1.getplastic()==one_3.getplastic()))))&&!(((i1.getglass()==one_3.getglass())&&(i1.getmetal()==one_3.getmetal())&&(i1.getpaper()==one_3.getpaper())&&(i1.getorganic()==one_3.getorganic())&&(i1.getplastic()==one_3.getplastic()))))
                {
                    cost3_1_1_1_1=Sorter::cost(i,i1);//перепишем минимум
                    one_4=i1;//созраним копию
                }
            }
        }
        result_cost=min(cost_4,cost_3+cost_3_1);//ищем минимальную итоговую стоимомть
        result_cost=min(cost_2_2+cost_2_1,result_cost);
        result_cost=min(cost_2_2+cost_2_1_1+ cost_22_1_1,result_cost);
        result_cost=min(cost_1+cost_1_1_1_1+cost2_1_1_1_1+cost3_1_1_1_1,result_cost);
        //заполняем сеты заводов
        if(result_cost == cost_4)
        {
            result_plants.insert(quadro);
        }
        else if (result_cost == cost_3+cost_3_1)
        {
            result_plants.insert(trio);
            result_plants.insert(trio_1);
        }
        else if(result_cost == cost_2_2+cost_2_1)
        {
            result_plants.insert(duo);
            result_plants.insert(duo_2_1);
        }else if(result_cost == cost_2_2+cost_2_1_1+ cost_22_1_1)
        {
            result_plants.insert(duo);
            result_plants.insert( duo_1_1);
            result_plants.insert(duo_1_2);
        }else
        {

            result_plants.insert(one_1);
            result_plants.insert(one_2);
            result_plants.insert(one_3);
            result_plants.insert(one_4);
        }

        result.insert(pair<Container,set<Plant>>(i,result_plants));//вносим всё в результат
        break;
        }
        case(5):
        {

        }
        }
   }
}
