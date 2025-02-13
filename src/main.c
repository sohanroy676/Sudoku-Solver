#include <stdio.h>
#include ".\include\game.h"
#include ".\include\solver.h"

int main() {
    printf("Sudoku Solver - Project by SOHAN ROY TALARI (1602-23-733-119)\n");
    pause();
    reset_board(board);
    mainloop(board, solver);
    clear_screen();
    info();
    print_board(board);
    pause();
} 