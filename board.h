#ifndef BOARD_H
#define BOARD_H

class board{
	private:
		int x, y;
		int bSize;
		int winX, winY;
    public:
        board();
        int get_x();
        int get_y();
        int get_bSize();
        int get_winX();
        int get_winY();
};

#endif
