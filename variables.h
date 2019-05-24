#ifndef VARIABLES_H
#define VARIABLES_H
#include "snake.h"
#include "cake.h"
#include "board.h"
#include "gameController.h"

board b;

static int mainMenu;
static int subMenu1;
static int subMenu2;

char dir = 'u'; /*Direction*/
int snake_size = 5;  //Snack Size
int gap = 100;   //Time to move next step
bool stop = 0;
int point = 0;

cake c;
snake s[100];
gameController snake_n_cake;  //Declare Game Class

#endif
