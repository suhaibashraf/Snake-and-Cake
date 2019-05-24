#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

class gameController{
	public:
	    void genObsta();
	    void drawObsta();
		void over();
		void drawSnake();
		void stroke();
		static void keyboard(int key, int a, int b);
};

#endif
