/*!
\file container.cpp
\b реализация функций контейнра
*/
#include "container.h"
Container::Container()
{
    id=0;
    x=0;
    y=0;
    metal=0;
    organic=0;
    plastic=0;
    paper=0;
    glass=0;
   // name=nullptr;
}
ostream& operator<<(ostream& out , const Container& plant)
{
    out << plant.id << plant.x << plant.y << plant.metal << plant.paper << plant.glass << plant.organic;
    return out ;
}
int Container::getid()
{
    return id;
}
int Container::getcoordx()
{
    return x;
}
int Container::getcoordy()
{
    return y;
}
bool Container::getmetal()
{
    return metal;
}
bool Container::getpaper()
{
    return paper;
}
bool Container::getorganic()
{
    return organic;
}
bool Container::getplastic()
{
    return plastic;
}
bool Container::getglass()
{
    return glass;
}
void Container::setmat_metal(bool a)
{
 metal=a;
}
void Container::setmat_paper(bool a)
{
    paper=a;
}
void Container::setmat_organic(bool a)
{
    organic=a;
}
void Container::setmat_plastic(bool a)
{
    plastic=a;
}
void Container::setmat_glass(bool a)
{
    organic=a;
}
void Container::setid(int number)
{
    id=number;
}
void Container::setx(int ix)
{
   x=ix;
}
void Container::sety(int iy)
{
    y=iy;
}
Container Container::operator =(const Container&equal){
    if(this != &equal){
        this->id= equal.id;
        this->x= equal.x;
        this->y= equal.y;
        this->metal= equal.metal;
        this->glass= equal.glass;
        this->paper= equal.paper;
        this->organic= equal.organic;
        this->plastic= equal.plastic;
    }
    return *this;
}
