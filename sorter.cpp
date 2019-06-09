#include "sorter.h"
#include <fstream>
#include <set>
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
