#ifndef GAME
#define GAME
short board[9][9];

void pause();
void reset_board(short b[9][9]);
void info();
void clear_screen();
void print_board(short b[9][9]);
short is_valid(short b[9][9], short r, short c, short val);
short add_value(short b[9][9], short r, short c, short val);
void create_random_board(short b[9][9], int n);
void mainloop(short b[9][9], void (*solver)(short b[9][9]));
#endif 