#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

void pause() { 
    char a; 
    printf("Enter any number to continue: "); 
    scanf("%d", &a); 
} 

void reset_board(short b[9][9]) {
    for (short i = 0; i < 9; i++) {
        for (short j = 0; j < 9; j++) {
            b[i][j] = 0;
        }
    }
} 

void info() { 
    printf("**************************************************************************\n"); 
    printf("Sudoku - Project by SOHAN ROY TALARI - PPS Assignment 2\n"); 
    printf("This projects contains the following concepts:\n"); 
    printf("\t1)Flowcharts for all the decisions and flow of program\n"); 
    printf("\t2)Algorithms for the Solver\n"); 
    printf("\t3)Various Operators, Keywords, Special Symbols, Identifiers, ...\n"); 
    printf("\t4)Different Datatypes\n"); 
    printf("\t5)Type Conversions\n"); 
    printf("\t6)Selection Control Statements: if, else if, else\n"); 
    printf("\t7)Case Control Statements: switch\n"); 
    printf("\t8)Loop Control Statements(Iterations): for, while, do while\n"); 
    printf("\t9)Jump Statements: break, continue\n"); 
    printf("\t10)Functions - call by value and address\n"); 
    printf("\t11)Storage Classes\n");
    printf("\t12)Arrays - 1 dimentional\n"); 
    printf("\t13)Arrays - 2 dimentional\n"); 
    printf("\t14)Pointers\n"); 
    printf("\t15)Multiple files - User defined header/include files\n"); 
    printf("**************************************************************************\n"); 
} 

void clear_screen() {
    printf("\e[1;1H\e[2J"); 
} 

void print_board(short b[9][9]) {
    short j;
    char c;
    for (short i = 0; i < 9; i++) {
        c = i%3 ? '-' : '_'; 
        for (j = 0; j < 37; j++) {
            printf("%c", c);
        }
        printf("\n");
        for (j = 0; j < 9; j++) {
            if (j % 3 == 0) printf("|"); 
            else printf(":"); 
            if (b[i][j]) printf(" %d ", b[i][j]); 
            else printf("   "); 
        } 
        printf("|\n");
    } 
    for (j = 0; j < 37; j++) printf("_"); 
    printf("\n"); 
}

short is_valid(short b[9][9], short r, short c, short val) { 
    short cellR = (r/3)*3, cellC = (c/3)*3; 
    if (b[r][c]) return 0; 
    for (short i = 0; i < 9; i++) {
        if ((i != c && b[r][i] == val) || (i != r && b[i][c] == val) ||
            (cellR+i/3 != r && cellC+i%3 != c && b[cellR+i/3][cellC+i%3] == val)) {
                return 0;
            }
    }
    return 1;
}

short add_value(short b[9][9], short r, short c, short val) { 
    if (r < 0 || r > 8 || c < 0 || c > 8 || val < 0 || val > 9 || !is_valid(b, r, c, val)) return 0; 
    b[r][c] = val;
    return 1;
} 

void create_random_board(short b[9][9], int n) { 
    srand(time(NULL)); 
    int i = 0, row, col, val; 
    do {
        row = rand() % 9; 
        col = rand() % 9; 
        val = rand() % 9 + 1; 
        if (is_valid(b, row, col, val)) {
            b[row][col] = val;
            ++i;
        }
    } while (i < n);
}

void mainloop(short b[9][9], void (*solver)(short b[9][9])) { 
    short run = 1, cmd, r, c, val;
    while (run) {
        clear_screen();
        info();
        print_board(b);
        printf("Enter command {0:QUIT, 1:Enter Value, 2:Solve, 3:CreateRandom}: ");
        scanf("%hd", &cmd);
        switch (cmd) {
            case 0:
                run = 0;
                break;
            case 1: 
                printf("Enter {ROW COL VALUE}: ");
                scanf("%hd %hd %hd", &r, &c, &val);
                if (!val && r > 0 && r <= 9 && c > 0 && c <= 9) b[r][c] = val;
                else if (!add_value(b, r-1, c-1, val)) {
                    printf("Invalid\n");
                    pause();
                }
                break;
            case 2: 
                solver(b);
                return;
            case 3:
                printf("Enter num of inital values(1-20): ");
                scanf("%hd", &val);
                if (val > 0 && val <= 20) {
                    reset_board(b);
                    create_random_board(b, val);
                } else {
                    printf("Invalid\n");
                    pause();
                }
                break;
            default:
                printf("Invalid\n");
                pause();
        }
    }
}