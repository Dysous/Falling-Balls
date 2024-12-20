#ifndef FORCE_H_INCLUDED
#define FORCE_H_INCLUDED
#include <iostream>
#include <ostream>
using namespace std;
class force{
    private:
        double magnitude;
        double yVelocity;
        double xVelocity;

    public:
        force(); //default constructor
        force(double m, double x, double y); //set constructor

        /*
        * description: sets the magnitude of the force
        * return: n/a
        * precondition: a force object exists
        * postcondition: the force’s magnitude is updated
        */
        void setMagnitude(double m);

        /*
        * description: accesses the magnitude value
        * return: double
        * precondition: a force object exists
        * postcondition: the force’s magnitude is returned
        */
        double getMagnitude()const;

        /*
        * description: accesses the velocity in the x-direction
        * return: double
        * precondition: a force object & xVelocity value exists
        * postcondition: the force’s x-velocity is returned
        */
        double getVelX()const;

        /*
        * description: accesses the velocity in the y-direction
        * return: double
        * precondition: a force object & yVelocity value exists
        * postcondition: the force’s y-velocity is returned
        */
        double getVelY()const;

        /*
        * description: updates the velocity in the x-direction
        * return: n/a
        * precondition: a force object & xVelocity value exists
        * postcondition: the force’s x-velocity is updated
        */
        void setVelX(double);
        /*
        * description: updates the velocity in the y-direction
        * return: n/a
        * precondition: a force object & yVelocity value exists
        * postcondition: the force’s y-velocity is updated
        */
        void setVelY(double);
        /*
        * description: = sign sets magnitude, xVelocity, and yVelocity to other force’s values
        * return: force
        * precondition: 2 force objects exist
        * postcondition: force values set to other force values
        */
        force operator=(const force& other);

};
#endif // FORCE_H_INCLUDED
