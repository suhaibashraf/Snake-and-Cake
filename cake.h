#ifndef CAKE_H
#define CAKE_H

class cake{  //Cake Class
	private:
		int x, y;  //Direction to appear
    public:
        int get_x();
        int get_y();
		void gen();
		void draw();
};

#endif
