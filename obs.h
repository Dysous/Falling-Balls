#ifndef OBS_H_INCLUDED
#define OBS_H_INCLUDED

#include "point.h"
#include "SDL_Plotter.h"
#include <cmath>
using namespace std;
class Obs{
private:
    vector <Obs> obstacles;
    point_t loc;
    int radius;
    color _color;
    int hp;
    int round;
public:
    Obs(); //default constructor

    /*
     * description: set location of an obstacle
     * return: n/a
     * precondition: a point_t object exists
     * postcondition: reassigns point_t value
    */
    void setLoc(point_t);

    /*
     * description: sets radius of an obstacle
     * return: n/a
     * precondition: an integer exists
     * postcondition: reassigns radius value
    */
    void setRadius(int);


    /*
     * description: sets color of an obstacle
     * return: n/a
     * precondition: an obstacle object & color value exists
     * postcondition: reassigns color value
    */
    void setColor(color);

    /*
     * description: sets round number
     * return: n/a
     * precondition: obs object and int passed in
     * postcondition: reassigns private int round
    */
    void setRound(int);


    /*
     * description: adds an obstacle object to a vector
     * return: n/a
     * precondition: an obstacle object & vector exists
     * postcondition: pushes back obstacle value into
    */
    void addToVector(Obs);


    /*
     * description: accesses obstacle elements within the vector
     * return: obstacle vector
     * precondition: an obstacle vector exists
     * postcondition: returns obstacle objects
    */
    vector<Obs>& getVector();


    /*
     * description: sets health for obstacle
     * return: n/a
     * precondition: an obstacle object & integer value exists
     * postcondition: obstacle’s health is updated
    */
    void setHealth(int);


    /*
     * description: accesses health for obstacle
     * return: int
     * precondition: an obstacle object exists
     * postcondition: the obstacle’s health is returned
    */
    int getHealth() const;


    /*
     * description: accesses location of an obstacle
     * return: point_t (defined in point.h)
     * precondition: an obstacle object exists
     * postcondition: returns point_t of a specific location
    */
    point_t getLoc() const;


    /*
     * description: accesses radius of obstacle
     * return: int
     * precondition: an obstacle object exists
     * postcondition: returns radius measure of obstacle
    */
    int getRadius() const;


    /*
     * description: accesses color of obstacle
     * return: color
     * precondition: an obstacle object exists
     * postcondition: returns color of obstacle
    */
    color getColor() const;


    /*
     * description: creates a blank row for new obstacles at bottom
     * return: n/a
     * precondition: an obstacle object exists
     * postcondition: more obstacles appear after each turn
    */
    void newRow(SDL_Plotter&);


/*
 * description: updates location of obstacles after each turn
 * return: n/a
 * precondition: an obstacle object & SDL_Plotter reference exists
 * postcondition: decreases obstacle’s location (y-coordinate)
*/
    bool moveUp(SDL_Plotter&);


    /*
     * description: plots each pixel for obstacle
     * return: n/a
     * precondition: an obstacle object & SDL_Plotter reference exists
     * postcondition: each pixel is displayed on screen
    */
    void display(SDL_Plotter&);


    /*
     * description: plots each obstacle
     * return: n/a
     * precondition: an obstacle object & SDL_Plotter reference exists
     * postcondition: the obstacle is displayed on the screen
    */
    void displayObstacles(SDL_Plotter&);


    /*
     * description: reassigns y-coordinate of a point_t object
     * return: n/a
     * precondition: an obstacle object exists
     * postcondition: the obstacle’s y-coordinate is updated
    */
    void move();
};

#endif // OBS_H_INCLUDED

