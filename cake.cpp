#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>

#include "variables.h"
#include "cake.h"

int cake::get_x() {
    return x;
}

int cake::get_y() {
    return y;
}

void cake::gen() {
    x = rand() % b.get_x();
    y = rand() % b.get_y();
    for(int i = 0; i < snake_size; i++){
        if(x == s[i].x && y == s[i].y){
            cake::gen();
        }
    }
}

void cake::draw() {
    glColor3f(1, 0, 0);
    glRecti(x * b.get_bSize(), y * b.get_bSize(), (x + 1) * b.get_bSize(), (y + 1) * b.get_bSize() + 1);
}
