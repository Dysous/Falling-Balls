#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

#include "point.h"
#include "SDL_Plotter.h"
#include <cmath>
#include "force.h"
#include "obs.h"
using namespace std;
class Ball{
private:
    point_t loc;
    int radius;
    color _color;
    force velocity;

public:
    Ball(); //default constructor

     /*
     * description: sets location of ball
     * return: n/a
     * precondition: a point_t value exists
     * postcondition: the ball’s location is updated
    */
    void setLoc(point_t);


    /*
     * description: sets radius of ball
     * return: n/a
     * precondition: an integer exists
     * postcondition: the ball’s radius is updated
    */
    void setRadius(int);


    /*
     * description: sets color of ball
     * return: n/a
     * precondition: a color value exists
     * postcondition: the ball’s color is updated
    */
    void setColor(color);


    /*
     * description: sets force of ball
     * return: n/a
     * precondition: a force value exists
     * postcondition: the ball’s force is updated
    */
    void setVector(force);


    /*
     * description: accesses the location of the ball
     * return: point_t
     * precondition: a ball object exists
     * postcondition: returns the location of the ball
    */
    point_t getLoc() const;


    /*
     * description: accesses the radius of the ball
     * return: int
     * precondition: a ball object exists
     * postcondition: returns the radius of the ball
    */
    int getRadius() const;


    /*
     * description: accesses the color of the ball
     * return: color
     * precondition: a ball object exists
     * postcondition: returns the color of the ball
    */
    color getColor() const;

    /*
     * description: accesses the foce of the ball
     * return: force
     * precondition: a ball object exists
     * postcondition: returns the force of the ball
    */
    force getVector() const; //change to getVel


    /*
     * description: plots each pixel for ball
     * return: n/a
     * precondition: a ball & SDL_Plotter object exists
     * postcondition: the ball is displayed on the screen
    */
    void display(SDL_Plotter&);


    /*
     * description: calculates which direction ball is shot from
     * return: n/a
     * precondition: a point_t & force value exists
     * postcondition: sets the direction of the ball
    */
    void shoot(point_t);


    /*
     * description: creates a wall around the canvas, so that if the ball is there,
     * the ball bounces off
     * return: n/a
     * precondition: a location exists
     * postcondition: the ball would bounce oppositely if it hits a certain point
    */
    void walls();


    /*
     * description: detects if ball has collided with an obstacle
     * return: bool
     * precondition: a ball & obstacle object exists
     * postcondition: if ball is collided, it subtracts a health from obstacle
     * and keeps track of obstacles that need to be destroyed
    */
    bool collide(vector<Obs>& obstacles);


    /*
     * description: updates the ball’s location
     * return: n/a
     * precondition: a ball object exists
     * postcondition: the ball moves up 1 pixel
    */
    void move();
};

#endif // BALL_H_INCLUDED

