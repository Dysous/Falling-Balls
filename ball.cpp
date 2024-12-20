#include <stdio.h>
#include "Ball.h"
#include "obs.h"
const double PI = 3.1415;
Ball::Ball(){
    loc.setX(80);
    loc.setY(80);
    radius = 8;
    _color.R = 25;
    _color.G = 255;
    _color.B = 255;
}
void Ball::setLoc(point_t point){
    loc = point;
}
void Ball::setRadius(int r){
    radius = r;
}
void Ball::setColor(color c){
    _color = c;
}
point_t Ball::getLoc() const{
    return loc;
}
int Ball::getRadius() const{
    return radius;
}
color Ball::getColor() const{
    return _color;
}
void Ball::display(SDL_Plotter& g){
    for (int x = -radius; x <= radius; x++){
        for(int y = -radius; y <= radius; y++){
            if (radius >= sqrt(pow(x, 2) + pow(y, 2))){
                g.plotPixel(x+loc.getX(), y+loc.getY(), _color);
            }
        }
    }
}
void Ball::move(){
    loc.setX(loc.getX() + velocity.getVelX()*velocity.getMagnitude());
    loc.setY(loc.getY() + velocity.getVelY()*velocity.getMagnitude());
}

void Ball::shoot(point_t p2){
    force launch;
    point_t p1;
    p1.setX(250);
    p1.setY(50);
    int x1 = 250;
    double y1 = 50;
    double x2 = p2.getX();
    double y2 = p2.getY();
    launch.setMagnitude(0.0015);
    launch.setVelX(x2-x1);
    launch.setVelY(y2-y1);
    setVector(launch);
}

void Ball::setVector(force v){
    velocity = v;
}

void Ball::walls(){
    if(loc.getX() >= 500 - 8){//Right wall
        velocity.setVelX(velocity.getVelX()*-1);
    }
    if(loc.getX() <= 8){//Left wall
        velocity.setVelX(velocity.getVelX()*-1);
    }
    if(loc.getY() <= 8){//Top wall
        velocity.setVelY(velocity.getVelY()*-1);
    }
}

force Ball::getVector() const{
    return velocity;
}

bool Ball::collide(vector<Obs>& obstacles){
    bool collision = false;
    for(int i = 0; i < obstacles.size(); i++){
        //delta x and y and distance between points
        double dx = getLoc().getX() - obstacles.at(i).getLoc().getX();
        double dy = getLoc().getY() - obstacles.at(i).getLoc().getY();
        double dist = sqrt(dx*dx + dy*dy);
        if(dist <= 8+25){ //detect collision adding radii together
            obstacles.at(i).setHealth(obstacles.at(i).getHealth()-1);
            if(obstacles.at(i).getHealth() == 0){
                point_t p;
                obstacles.at(i).move();
            }
            double nx = dx/dist;
            double ny = dy/dist;
            double vx = velocity.getVelX();
            double vy = velocity.getVelY();

            velocity.setVelX(vx-2*nx*(vx*nx+vy*ny));
            velocity.setVelY(vy-2*ny*(vx*nx + vy*ny));

            collision = true;
        }
    }
    return collision;
}
