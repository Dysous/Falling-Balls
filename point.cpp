#include "point.h"
#include <cmath>
using namespace std;
point_t::point_t(double x, double y){
    this->x = 0;
    this->y = 0;
}
void point_t::setX(double x){ //put class:: before function to connect it to class
    this->x = x;
}
void point_t::setY(double y){
    this->y = y;
}

double point_t::getX() const{
    return x;
}
double point_t::getY() const{
    return y; //only member 'y' so there is no confusion
}


double point_t::distance(const point_t& other) const{
    return sqrt(pow(getX()-other.getX(), 2) + pow(getY()-other.getY(), 2));
}

point_t point_t::operator=(point_t& other){
    setX(other.getX());
    setY(other.getY());
    return *this;
}
