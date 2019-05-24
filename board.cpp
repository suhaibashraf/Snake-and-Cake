#include "board.h"

board::board(){
    x = 60;
    y = 30;
    bSize = 20;
    winX = x * bSize;
    winY = y * bSize;
}

int board::get_x() {
    return x;
}

int board::get_y() {
    return y;
}

int board::get_bSize() {
    return bSize;
}

int board::get_winX() {
    return winX;
}

int board::get_winY() {
    return winY;
}
