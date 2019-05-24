#include <windows.h>
#include <GL/glut.h>

#include "variables.h"
#include "gameController.h"
#include "board.h"

void gameController::over() {
    exit(0);
}

void gameController::drawSnake() {
    glColor3f(1, 1, 0);
    glRecti(s[0].x * b.get_bSize() - 1, s[0].y * b.get_bSize(), (s[0].x + 1) * b.get_bSize(), (s[0].y + 1) * b.get_bSize() + 1); //Create the rest of the blocks of snake
    glColor3f(0, 1, 0);
    for(int i = 1; i < snake_size; i++){
        glRecti(s[i].x * b.get_bSize() - 1, s[i].y * b.get_bSize(), (s[i].x + 1) * b.get_bSize(), (s[i].y + 1) * b.get_bSize() + 1); //Create the rest of the blocks of snake
    }
}

void gameController::genObsta() {
    for(int i = 0; i < obs_size; i++){
        obs[i].x = rand() % b.get_x();
        obs[i].y = rand() % b.get_y();
        while(c.get_x() == obs[i].x && c.get_y() == obs[i].y){
            obs[i].x = rand() % b.get_x();
            obs[i].y = rand() % b.get_y();
        }
        for(int j = 0; j < snake_size; j++){
            while(obs[i].x == s[j].x && obs[i].y == s[j].y){
                obs[i].x = rand() % b.get_x();
                obs[i].y = rand() % b.get_y();
            }
        }
    }
}

void gameController::drawObsta(){
    glColor3f(1, 1, 1);
    for(int i = 0; i < obs_size; i++){
        glRecti(obs[i].x * b.get_bSize(), obs[i].y * b.get_bSize(), (obs[i].x + 1) * b.get_bSize(), (obs[i].y + 1) * b.get_bSize() + 1);
    }
}

void gameController::stroke() {
    for(int i = snake_size; i > 0; i--) {
        if(stop==1){
            s[i].x = s[i-1].x;
            s[i].y = s[i-1].y;  //changing position of next block to current block
        }
    }
    switch(dir){   //Changing Direction
        case 'u':
            ++s[0].y;
        break;
        case 'r':
            ++s[0].x;
        break;
        case 'd':
            --s[0].y;
        break;
        case 'l':
            --s[0].x;
        break;
    }
    if(c.get_x() == s[0].x && c.get_y() == s[0].y) {
        snake_size++;  //Increase Snake length
        c.gen(); // Generate new cake
        point++;
        if(gap > 1)
            gap -= gap / 20;   //Increase Speed
    }
    if(s[0].x < 0 || s[0].x >= b.get_x() || s[0].y < 0 || s[0].y >= b.get_y()) //Hit walls
        over();  // End
        //stop = 0;
    for(int i = 1; i < snake_size; i++)
        if(s[0].x == s[i].x && s[0].y == s[i].y)
            over();
            //stop = 0;
    for(int i = 1; i < obs_size; i++)
        if(s[0].x == obs[i].x && s[0].y == obs[i].y)
            over();
           //stop = 0;
}

void gameController::keyboard(int key, int a, int b) {
    switch(key) {
        case 101:  //ASCCI of Up button
            if(dir != 'd')  //If not downside
                dir = 'u';  //upside
        break;
        case 102:  //ASCCI of Right button
            if(dir != 'l')  //If not Left
                dir = 'r';  //Right
        break;
        case 103:  //ASCCI of Down button
            if(dir != 'u')  //if not up
                dir = 'd';  //down
        break;
        case 100:  //ASCCI of Left Button
            if(dir != 'r')  //if not Right
                dir = 'l';  //left
        break;
    }
}
