#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <ostream>
#include <iostream>
using namespace std;
class point_t{ //class declaration
    private:
        double x, y;
    public:
        //constructor is implicitly envoked (run automatically)
         /*
         * description: default constructor for point_t object
         * return: n/a
         * precondition: point_t class exists
         * postcondition: creates a point_t object
        */
        point_t(double x=0, double y=0);
         /*
         * description: sets the x value of the point object
         * return: void
         * precondition: point exists
         * postcondition: value in parameter set to x of point
        */
        void setX(double);
         /*
         * description: sets the y value of the point object
         * return: void
         * precondition: point exists
         * postcondition: value in parameter set to y of point
        */
        void setY(double);
         /*
         * description: gets the x value of the point object
         * return: double
         * precondition: point exists
         * postcondition: returns x value of point
        */
        double getX() const;
         /*
         * description: gets the y value of the point object
         * return: double
         * precondition: point exists
         * postcondition: returns y value of point
        */
        double getY() const;

         /*
         * description: calculates distance to other parameter point
         * return: double
         * precondition: 2 points exist
         * postcondition: returns distance from point to parameter point
        */
        double distance(const point_t&) const;

         /*
         * description: = sign sets x and y to other point’s x and y
         * return: double
         * precondition: 2 points exist
         * postcondition: other x and y’s values set to point
        */
         point_t operator= (point_t&);



};

#endif // POINT_H_INCLUDED

