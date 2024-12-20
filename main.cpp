//Authors: Noah Mathew, Andrew Crotwell, Emily Wokoek, Drin Ymeri, Faith Ota
//Noah: Programming, collisions, mathematics, sound
//Andrew: Mathematics, physics, debugging, catering
//Emily: Graphics, color, design, ball class, obs class
//Drin: Comments, game design, artistic input, morale support
//Faith: Comments, formatting, program structure, management
//Assignment Title: Falling Balls
//Assignment Description: Shoot falling small balls to break objects
//Due Date: 12/6/2023
//Date Created: 12/1/2023
//Date Last Modified: 12/6/2023

#include <iostream>
#include <iomanip>
#include <ostream>
#include "SDL_Plotter.h"
#include "point.h"
#include "force.h"
#include "Ball.h"
#include "obs.h"

using namespace std;
const double PI = 3.1415;
const force gravity(0.0001, 0, 0.6);

int main(int argc, char** argv) {
    //Data Abstraction:
    color bg(0,0,0);
    bool gameOver = false;
    SDL_Plotter g(500, 500);
    g.initSound("glassbreak.mp3");
    g.initSound("shoot.mp3");
    char key;
    color c;
    point_t p2;
    Ball ball;
    Obs obstacles;
    int roundCount = 0;
    int score = 0;
    obstacles.setRound(roundCount);
    //Game Start:
    for(int x = 0; x < 500;x++){//Background color
        for(int y = 0;y<500;y++){
            g.plotPixel(x,y,bg);
        }
    }
    obstacles.newRow(g);
    obstacles.displayObstacles(g);
    point_t p;
    p.setX(250);
    p.setY(50);
    ball.setLoc(p);
    ball.display(g);
    g.update();

    while (!g.getQuit()){
        //Quit Detect:
        if(g.kbhit() || gameOver){
            key = g.getKey();
            if(key == 'q' || gameOver){
                g.setQuit(true);
            }
        }
        g.update();
        //OnClick -> Shoot
        if(g.mouseClick()){
            g.playSound("shoot.mp3");
            point p1 = g.getMouseClick();
            p2.setX(p1.x);
            p2.setY(p1.y);
            ball.display(g);
            ball.shoot(p2);
            //Shoot
            while((ball.getLoc()).getY() < 525){
                ball.move();
                ball.display(g);
                obstacles.displayObstacles(g);
                //Gravity:
                force newForce = ball.getVector();
                newForce.setVelY(newForce.getVelY()+gravity.getVelY());
                ball.setVector(newForce);
                //Collision:
                ball.walls();
                if(ball.collide(obstacles.getVector())){
                    obstacles.displayObstacles(g);
                    score++;
                    g.playSound("glassbreak.mp3");
                }
                g.update();
                g.clear();

                for(int x = 0; x < 500;x++){//Background color set after clear
                    for(int y = 0;y<500;y++){
                        g.plotPixel(x,y,bg);
                    }
                }
            }
            //New Round:
            if(ball.getLoc().getY() > 520){
                roundCount++;
                obstacles.setRound(roundCount);
                ball.setLoc(p);
                ball.display(g);
                if(obstacles.moveUp(g)){
                    gameOver = true;
                }
                obstacles.newRow(g);
                obstacles.displayObstacles(g);
                g.update();

            }
        }

    }
    cout << "Game Over!" << endl;
    cout << "Score: " << score << endl;

    return 0;
}
