//
// ***REQUEST***
//
// ***Mike Belfield***
// 
//***Using SPL and CS50*** 
//
//***03-28-2014***
//
//
// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include "gevents.h"
#include "gobjects.h"
#include "gwindow.h"

// height and width of game's window in pixels
#define HEIGHT 800
#define WIDTH 600

// defining road dimensions and placemet
#define RVW (WIDTH/10)
#define RVx ((WIDTH+RVW)/2)
#define RVH (HEIGHT)
#define RVy (0)
#define RHW (WIDTH)
#define RHx (0)
#define RHH (RVW)
#define RHy ((HEIGHT+RHH)/2)
 
// radius AND diameter of player in pixels
#define RADIUS (RVW/2)
#define DIAM (RVW)

// lives
#define LIVES 3

// prototypes
void initRoadV(GWindow window);
void initRoadH(GWindow window);
GOval initPlayer(GWindow window);
//GRect initPaddle(GWindow window);
//GLabel initScoreboard(GWindow window);
//void updateScoreboard(GWindow window, GLabel label, int points);
//GObject detectCollision(GWindow window, GOval ball);
//double drand48(void);

int main(void)
{
    // seed pseudorandom number generator
    //srand48(time(NULL));

    // instantiate map of town
    GWindow town = newGWindow(WIDTH, HEIGHT);
    setFilled(town, true);
    setColor(town, "brown");
    

    // instantiate roads
    initRoadV(window);
    initRoadH(window);

    // instantiate ball, centered in middle of window
    GOval Player = initPlayer(window);

    // instantiate paddle, centered at bottom of window
    //GRect paddle = initPaddle(window);
   
    // instantiate scoreboard, centered in middle of window, just above ball
    //GLabel label = initScoreboard(window);

    // number of bricks initially
    //int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially and brick tracking
    //int points = 0;
    //int bcount = 0;
    
    // beginning velocity of ball
    //double BV = drand48();
    //double xvelocity = 2.5 + BV;
    //double yvelocity = xvelocity;

    // keep playing until game over
    while (lives > 0)
       
    {
    //moves ball
        //move(ball, xvelocity, yvelocity);
    //bounces off right side    
        //if (getX(ball) >= (getWidth(window)) - getWidth(ball))
        //{
           //xvelocity = -xvelocity;
        //}
     //bounces off left side   
        //else if (getX(ball) <= 0) 
        //{
            //xvelocity = -xvelocity;
        //}
     //if the ball hits bottom of window   
        //if (getY(ball) >= (getHeight(window)) - getHeight(ball))
        //{
            //lives = lives - 1;
            //setLocation(ball, (WIDTH/2) - RADIUS,(HEIGHT/2) - RADIUS);
            //waitForClick();
        //}
     //bounces off top   
        //else if (getY(ball) <= 0)
        //{
            //yvelocity = -yvelocity;
        //}
     //to make ball more visable   
        //pause(10);
     //to move Player with mouse   
        GEvent mousem = getNextEvent(MOUSE_EVENT);
     //if mouse is moving, paddle follows mouse       
        if (mousem != NULL)
        {
            if (getEventType(mousem) == MOUSE_MOVED)
            {
                double x = getX(mousem) - getWidth(paddle) / 2;
                double y = (HEIGHT - (HEIGHT/6));
                setLocation(paddle, x, y);
            }
        }
        //test code
        //else if (mousem == NULL)
        //{
        //  setLocation(paddle, getX(ball) - RADIUS, (HEIGHT - (HEIGHT/6)));
        //}
        
        //**collision detection
    //    GObject object = detectCollision(window, ball);
        //in case of a collision
    //    if (object != NULL)
    //    {
        //paddle collision bounce and give a point
    //    if (object == paddle)
    //    {
    //        points = points + 1;
    //        updateScoreboard(window, label, points);
    //        yvelocity = -yvelocity;
    //    }
        //if brick remove brick, give points, update score and bounce
    //    else if (strcmp(getType(object), "GRect") == 0)
    //    {
    //        removeGWindow(window, object);
    //        points = points + 2;
    //        bcount = bcount + 1;
    //        updateScoreboard(window, label, points);
    //        yvelocity = -yvelocity;
        //if all bricks are gone end    
    //        if (bcount == 50)
    //            {
    //                waitForClick();
    //                closeGWindow(window);
    //                return 0;
    //            }            
    //    }
    //    }
    //}

    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes roads
 */
void initRoadV(GWindow window)
{   
    GRect RoadV = newGRect(RVx, RVy, RVW, RVH);
    setFilled(RoadV, true);
    setColor(RoadV, "BROWN")
}

void initRoadH(GWindow window)
{

    GRect RoadH = newGRect(RHx, RHy, RHW, RHH);
    setFilled(RoadH, true);
    setColor(RoadH, "BROWN");
}

           

/**
 * Instantiates Player in the bottom center of window.  Returns Player.
 */
GOval initPlayer(GWindow window)
{
    GOval Player = newGOval((WIDTH/2) - RADIUS,HEIGHT - RADIUS,DIAM, DIAM);
    setFilled(Player, true);
    setColor(Player, "BLACK");
    add(window, Player); 
    return Player;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
//GRect initPaddle(GWindow window)
//{
  //GRect padd = newGRect((WIDTH/2) - 30,(HEIGHT - (HEIGHT / 6)),60,10);
    //setFilled(padd, true);
    //setColor(padd, "BLACK");
    //add(window, padd);
    //return padd;
//}
/**
 * Instantiates, configures, and returns label for scoreboard.
 */
//GLabel initScoreboard(GWindow window)
//{   
  //  double lx, ly;
    //GLabel label = newGLabel("SCORE");
    //setColor(label, "RED");
    //setSize(label, 40,40) <- didnt work...
    //lx = ((getWidth(window)/2)- 22);
    //ly = (getHeight(window) - (getFontAscent(label) * 2));
    //setLocation(label, lx, ly);
    //add(window, label);   
    //return label;
//}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
//void updateScoreboard(GWindow window, GLabel label, int points)
//{
    // update label
  //  char s[12];
    //sprintf(s, "%i", points);
    //setLabel(label, s);

    // center label in window** changed to below the paddle
    //double sx, sy;
    //sx = (getWidth(window)/2);
    //sy = (getHeight(window) - (getFontAscent(label) * 2));
   // setLocation(label, sx, sy);
//}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are   **pset doesnt require bounding box detection
 * outside the ball's GOval, and so the ball can't collide with    on bricks or paddles making game mechanics buggy
 * itself).  Returns object if so, else NULL.
 */
//GObject detectCollision(GWindow window, GOval ball)
//{
    // ball's location
  //  double x = getX(ball);
//    double y = getY(ball);

    // for checking for collisions
//    GObject object;

    // check for collision at ball's top-left corner
//    object = getGObjectAt(window, x, y);
//    if (object != NULL)
//    {
//        return object;
//    }

    // check for collision at ball's top-right corner
//    object = getGObjectAt(window, x + 2 * RADIUS, y);
//    if (object != NULL)
//    {
//        return object;
//    }

    // check for collision at ball's bottom-left corner
//    object = getGObjectAt(window, x, y + 2 * RADIUS);
//    if (object != NULL)
//    {
//        return object;
//    }

    // check for collision at ball's bottom-right corner
//    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
//    if (object != NULL)
//    {
//        return object;
//    }

    // no collision
//    return NULL;
}
