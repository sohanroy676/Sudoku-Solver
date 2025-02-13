#include <stdio.h>

short is_valid(short b[9][9], short r, short c, short val);

void get_valid_nums(short b[9][9], short r, short c, short num, short v[10]) {
    v[0] = 0;
    for (short i = num+1; i < 10; i++) {
        if (is_valid(b, r, c, i)) {
            v[++v[0]] = i;
        }
    }
}

short is_solved(short b[9][9]) { 
    for (short i = 0; i < 9; i++) for (short j = 0; j < 9; j++) if (!is_valid(b, i, j, b[i][j])) return (short)0; 
    return (short)1;
}

void solver(short b[9][9]) { 
    short row = 0, col = 0, num = 0, validNums[10];
    short history[82][3];
    history[0][0] = 0;
    validNums[0] = 0;
    while (row < 9 && col < 9) {
        if (!b[row][col]) {
            get_valid_nums(b, row, col, num, validNums);
            if (validNums[0]) {
                num = validNums[1];
                b[row][col] = num;
                history[0][0] += 1;
                history[history[0][0]][0] = row;
                history[history[0][0]][1] = col;
                history[history[0][0]][2] = num;
                num = 0;
            } else {
                b[row][col] = 0;
                row = history[history[0][0]][0];
                col = history[history[0][0]][1];
                num = history[history[0][0]][2];
                history[0][0] -= 1;
                b[row][col] = 0;
                continue;
            }
        }
        ++col;
        if (col >= 9) {
            col = 0;
            ++row;
        }
    }
} 