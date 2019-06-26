/*!
\file plant.h
\brief заголовочный файл с реализацией функций завода
*/
#include "plant.h"
Plant::Plant()
{
    id=0;
    metal=0;
    glass=0;
    paper=0;
    plastic=0;
    organic=0;
 //   name=nullptr;
    distance_cost=numeric_limits<int>::max();
    x=0;
    y=0;
}
ostream& operator<<(ostream& out , const Plant& plant)
{
    out << plant.id << plant.x << plant.y << plant.metal << plant.paper << plant.glass << plant.organic;
    return out ;
}
int Plant::get_distance_cost()
{
    return distance_cost;
}
void Plant::set_distance_cost(int cost)
{
    distance_cost=cost;
}
int Plant::getid()
{
    return id;
}
int Plant::getcoordx()
{
    return x;
}
int Plant::getcoordy()
{
    return y;
}
bool Plant::getmetal()
{
    return metal;
}
bool Plant::getpaper()
{
    return paper;
}
bool Plant::getorganic()
{
    return organic;
}
bool Plant::getplastic()
{
    return plastic;
}
bool Plant::getglass()
{
    return glass;
}
void Plant::setmat_metal(bool a)
{
 metal=a;
}
void Plant::setmat_paper(bool a)
{
    paper=a;
}
void Plant::setmat_organic(bool a)
{
    organic=a;
}
void Plant::setmat_plastic(bool a)
{
    plastic=a;
}
void Plant::setmat_glass(bool a)
{
    organic=a;
}
void Plant::setid(int number)
{
    id=number;
}
void Plant::setx(int ix)
{
   x=ix;
}
void Plant::sety(int iy)
{
    y=iy;
}
Plant Plant::operator =(const Plant&equal){
    if(this != &equal){
        this->id= equal.id;
        this->x= equal.x;
        this->y= equal.y;
        this->metal= equal.metal;
        this->glass= equal.glass;
        this->paper= equal.paper;
        this->organic= equal.organic;
        this->plastic= equal.plastic;
        this->distance_cost= equal.distance_cost;
    }
    return *this;
}
