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
void Sorter::sorter_container_to_plant(set<Container> Containers_list, set<Plant> Plants_list)
{
    set<Container> single_c, duo_c, trio_c, quadro_c, penta_c;
    set<Plant> single_p, duo_p, trio_p, quadro_p, penta_p;
    for (set<Container>::iterator it = Containers_list.begin();it!=Containers_list.end();it++)
    {
        auto c=*it;
        int a = c.get_number_of_types();
        if(a==1)
            single_c.insert(c);
        if(a>=2)
            duo_c.insert(c);
        if(a>=3)
            trio_c.insert(c);
        if(a>=4)
            quadro_c.insert(c);
        if(a==5)
            penta_c.insert(c);

    }
    for(set<Plant>::iterator it = Plants_list.begin();it!=Plants_list.end();it++)
    {
        auto p=*it;
        int a = p.get_number_of_types();
        if(a==1)
            single_p.insert(p);
        if(a>=2)
            duo_p.insert(p);
        if(a>=3)
            trio_p.insert(p);
        if(a>=4)
            quadro_p.insert(p);
        if(a==5)
            penta_p.insert(p);
    }
    map<Container,Plant> singles_map_c;
    map<Plant,Container> singles_map_p;
    for (set<Container>::iterator iter = single_c.begin();iter!=single_c.end();iter++)
    {
        Plant pl;
        auto c=*iter;
        double mincost=INFINITY;
        for (set<Plant>::iterator i = Plants_list.begin();i!=Plants_list.end();i++)
        {
            auto p = *i;
            if(cost(c,p)<mincost&&((p.getmetal()&&c.getmetal())||(p.getglass()&&c.getglass())||(p.getpaper()&&c.getpaper())||(p.getorganic()&&c.getorganic())||(p.getplastic()&&c.getplastic())))
            {
                mincost=cost(c,p);
                pl=p;
            }
        }
        singles_map_c.insert(pair<Container,Plant>(c,pl));
        singles_map_p.insert(pair<Plant,Container>(pl,c));
    }
    map<Container,set<Plant>> duos_map_c;
    map<Plant,set<Container>> duos_map_p;
    double min_cost_duo=INFINITY;
    double min_cost_duo_singles_1 = INFINITY;
    double min_cost_duo_singles_2 = INFINITY;
    for (set<Container>::iterator iter = duo_c.begin();iter!= duo_c.end();iter++)
    {
        auto c=*iter;
        set<Plant> temp;
        Plant pl1;
        Plant pl2, pl3;
        for (set<Plant>::iterator it=duo_p.begin() ;it!=duo_p.end();it++)
        {
            auto p=*it;
            if(cost(c,p)<min_cost_duo&&((p.getmetal()&&c.getmetal())||(p.getglass()&&c.getglass())||(p.getpaper()&&c.getpaper())||(p.getorganic()&&c.getorganic())||(p.getplastic()&&c.getplastic())))
            {
                    min_cost_duo=cost(c,p);
                    pl1=p;
            }
        }
        for (set<Plant>::iterator it = Plants_list.begin();it!=Plants_list.end();it++)
        {
            auto p = *it;

            if(cost(c,p)<min_cost_duo_singles_1&&((p.getmetal()&&c.getmetal())^(p.getglass()&&c.getglass())^(p.getpaper()&&c.getpaper())^(p.getorganic()&&c.getorganic())^(p.getplastic()&&c.getplastic())))
            {
                min_cost_duo_singles_1=cost(c,p);
                pl2=p;
            }
            if(cost(c,p)<min_cost_duo_singles_2&&((p.getmetal()&&c.getmetal())^(p.getglass()&&c.getglass())^(p.getpaper()&&c.getpaper())^(p.getorganic()&&c.getorganic())^(p.getplastic()&&c.getplastic())))
            {
                if((((p.getmetal()&&c.getmetal())==1)&&((pl2.getmetal()&&c.getmetal())!=1))||(((p.getglass()&&c.getglass())==1)&&((pl2.getglass()&&c.getglass())!=1))||(((p.getpaper()&&c.getpaper())==1)&&((pl2.getpaper()&&c.getpaper())!=1))||(((p.getorganic()&&c.getorganic())==1)&&((pl2.getorganic()&&c.getorganic())!=1))||(((p.getplastic()&&c.getplastic())==1)&&((pl2.getplastic()&&c.getplastic())!=1)))
                {
                    min_cost_duo_singles_2=cost(c,p);
                    pl3=p;
                }
            }
        }
        double total_cost = min(min_cost_duo_singles_1+min_cost_duo_singles_2,min_cost_duo);
        if(total_cost==min_cost_duo_singles_1+min_cost_duo_singles_2)
        {
            temp.insert(pl2);
            temp.insert(pl3);
            duos_map_c.insert(pair<Container,set<Plant>>(c,temp));
        }
        else
        {
            temp.insert(pl1);
            duos_map_c.insert(pair<Container,set<Plant>>(c,temp));
        }
    }
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
