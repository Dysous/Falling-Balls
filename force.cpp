#include "force.h"
#include <cmath>

const double PI = 3.1415;
force::force(){
	magnitude = 0;
	xVelocity = 0;
	yVelocity = 0;
}

force::force(double m, double x, double y){
	magnitude = m;
	xVelocity = x;
	yVelocity = y;
}

void force::setMagnitude(double m){
	magnitude = m;
}

double force::getMagnitude()const{
	return magnitude;
}

force force::operator=(const force& other){
	setMagnitude(other.magnitude);
	setVelX(other.xVelocity);
	setVelY(other.yVelocity);
    return *this;
}

double force::getVelX()const{
    return xVelocity;
}
double force::getVelY()const{
    return yVelocity;
}
void force::setVelX(double x){
    xVelocity = x;
}
void force::setVelY(double y){
    yVelocity = y;
}
