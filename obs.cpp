#include <stdio.h>
#include "obs.h"
Obs::Obs(){
    loc.setX(80);
    loc.setY(80);
    radius = 25;
    _color.R = 255;
    _color.G = 25;
    _color.B = 25;
    hp = 1;
}
void Obs::setLoc(point_t point){
    loc = point;
}
void Obs::setRadius(int r){
    radius = r;
}
void Obs::setColor(color c){
    _color = c;
}
point_t Obs::getLoc() const{
    return loc;
}
int Obs::getRadius() const{
    return radius;
}
color Obs::getColor() const{
    return _color;
}
void Obs::display(SDL_Plotter& g){
    for (int x = -radius; x <= radius; x++){
        for(int y = -radius; y <= radius; y++){
            if (radius >= sqrt(pow(x, 2) + pow(y, 2))){
                g.plotPixel(x+loc.getX(), y+loc.getY(), _color);
            }
        }
    }
}
void Obs::move(){
    loc.setX(loc.getX() + 500);
}

void Obs::displayObstacles(SDL_Plotter& g){
    color green(0,255,0);
    color yellow(255,255,0);
    color red(255,0,0);
    for(int i =0; i < obstacles.size();i++){
        if(obstacles.at(i).getHealth() == 1){
            obstacles.at(i).setColor(green);
        }
        else if(obstacles.at(i).getHealth() == 2){
            obstacles.at(i).setColor(yellow);
        }
        else if(obstacles.at(i).getHealth() == 3){
            obstacles.at(i).setColor(red);
        }
        obstacles.at(i).display(g);

    }
}

void Obs::addToVector(Obs tempObs){
    obstacles.push_back(tempObs);
}

vector<Obs>& Obs::getVector(){
    return obstacles;
}

void Obs::newRow(SDL_Plotter& g){
    point_t tempPoint;
    double x = 50;
    int difficulty = round;
    if(round % 3){
        difficulty++;
    }
    if(difficulty > 10){
        difficulty = 10;
    }
    int chanceToAppear = 20 - difficulty;
    int cutoff = 5;
    int chance;
    int noBall = 0;
    color green(0,255,0);
    color yellow(255,255,0);
    color red(255,0,0);
    for(int i = 0; i < 5; i++){
        chance = rand() % chanceToAppear - noBall;
        if(chance < cutoff || noBall == 4){
            Obs tempBall;
            if(round < 3){ // rounds 1-3 sets all hp to 1
                tempBall.setHealth(1);
            }
            else if(round < 6){ // rounds 3-6 only 1-2hp
               tempBall.setHealth((rand()%2) +1);
            }
            else{//1-3hp
                tempBall.setHealth((rand()%3) +1);
            }
            if(noBall == 4){
                x = rand() % 5;
                x = (x*100) + 50;
            }
            tempPoint.setX(x);
            tempPoint.setY(475);

            tempBall.setLoc(tempPoint);
            if(tempBall.getHealth() == 1){
                tempBall.setColor(green);
            }
            else if(tempBall.getHealth() == 2){
                tempBall.setColor(yellow);
            }
            else if(tempBall.getHealth() == 3){
                tempBall.setColor(red);
            }
            addToVector(tempBall);
            g.update();

        }
        else{
            noBall++;
        }
        x+=100;

    }
}

bool Obs::moveUp(SDL_Plotter& g){
    bool gameOver = false;
    for(int i= 0; i < obstacles.size(); i++){
        point_t loc = obstacles.at(i).getLoc();
        if(loc.getX() < 500){ //only move up existing objects
            loc.setY(loc.getY() -100);
            obstacles.at(i).setLoc(loc);
            obstacles.at(i).display(g);
        }
        if(obstacles.at(i).getLoc().getY() < 100 ){
            gameOver = true;
        }
    }
    g.update();
    return gameOver;
}

void Obs::setHealth(int h){
    hp = h;
}
int Obs::getHealth() const{
    return hp;
}

void Obs::setRound(int n){
    round = n;
}
