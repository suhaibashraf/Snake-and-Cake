#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <math.h>

#include "cake.h"
#include "cake.cpp"
#include "snake.h"
#include "gameController.h"
#include "gameController.cpp"
#include "board.h"
#include "board.cpp"
#include "variables.h"


using namespace std;

void init() {
    //To generate snake from center of the screen
	for(int i = 0; i < snake_size; i++) {
		s[i].x = b.get_x() / 2;
		s[i].y = (b.get_y() + snake_size) / 2 - i;
	}
	c.gen();         //Generate Cake
	snake_n_cake.genObsta();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	snake_n_cake.drawSnake();  //generate Snake
	snake_n_cake.drawObsta();
	c.draw();  //generating cake
	snake_n_cake.drawObsta();
	glutSwapBuffers();
	system("cls");
	cout<<"Score: "<<point<<endl;
}

void timer(int = 0) {
    display();
	if(stop)
        snake_n_cake.stroke();  //Sync snake move with time
    glutTimerFunc(gap, timer, 0);  //Glut function for time

}

void menuFunc(int key){  //Menu Function handler
    switch(key){
        case 'x':
            exit(0);
        case 'p':
            stop = 0;
            break;
        case 's':
            stop = 1;
            break;
        case 1:
            gap = 300;
            obs_size = 10;
            snake_n_cake.genObsta();
            break;
        case 2:
            gap = 200;
            obs_size = 25;
            snake_n_cake.genObsta();
            break;
        case 3:
            gap = 100;
            obs_size = 50;
            snake_n_cake.genObsta();
            break;
    }
}

void gameMenu(){  //Function to Generate Menu
    subMenu1 = glutCreateMenu(menuFunc);

    glutAddMenuEntry("Pause",'p');
    glutAddMenuEntry("Start",'s');
    glutAddMenuEntry("Exit",'x');

    subMenu2 =glutCreateMenu(menuFunc);

    glutAddMenuEntry("Easy", 1);
    glutAddMenuEntry("Medium", 2);
    glutAddMenuEntry("Hard", 3);

    mainMenu = glutCreateMenu(menuFunc);

    glutAddSubMenu("Start", subMenu1);
    glutAddSubMenu("Level", subMenu2);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(b.get_winX(), b.get_winY());
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Snake and Cake");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, b.get_winX(), 0, b.get_winY());
	init();
	glutSpecialFunc(gameController::keyboard);
	glutDisplayFunc(display);
	glutTimerFunc(gap, timer, 0);
	gameMenu();
	glutMainLoop();
	return 0;
}
