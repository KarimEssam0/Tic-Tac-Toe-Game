#include <stdio.h>
#include "main.h"

char board[3][3];
char currentPlayer;
int anser ;

int main() {
    printf("\n");
    printf("which plays frist ? ");
    scanf(" %c", &currentPlayer);
    if (currentPlayer=='X'||currentPlayer=='O') {
        initializeBoard();

        int row, col;
        int ctr_X = 0, ctr_O = 0;
        while (1) {
            printBoard();
            printf("Player %c, Enter the row and the colum : ", currentPlayer);
            scanf("%d %d", &row, &col);

            if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
                printf("invalid choise, try again. \n");
                continue;
            }

            board[row][col] = currentPlayer;

            if (checkWin()) {
                printBoard();
                printf("Player %c won !\n\n", currentPlayer);

                if(currentPlayer=='X') {
                    ctr_X++;
                }
                else {
                    ctr_O++;
                }

                printf("Do you want to play another game (1 OR 0 ) ? ");
                scanf("%i",&anser);
                //getchar();
                if (anser ==1) {
                    initializeBoard();
                    continue;
                }
                else {
                    printf("\nThe Result \nplayer_X : player_O \n       %i : %i \n",ctr_X,ctr_O);
                    break;
                }
            }

            if (checkDraw()) {
                printBoard();
                printf("The game ended by drow! \n");
                ctr_X++;
                ctr_O++;
                printf("Do you want to play another game (1 OR 0 ) ? ");
                scanf("%i",&anser);
                getchar();
                if (anser ==1) {
                    initializeBoard();
                    continue;
                }
                else {

                    printf("\nThe Result \nplayer_X : player_O \n       %i : %i \n",ctr_X,ctr_O);

                    break;
                }
            }

            switchPlayer();
        }

        return 0;
    }else {
        printf("invalid choise !\n");
        //return 0;
        printf("\n");
        getchar();
        main();

    }

}
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

int checkWin() {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return 1;
            }
    }


    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return 1;
        }

    return 0;
}

int checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

void switchPlayer() {
    currentPlayer = 'X' + 'O' - currentPlayer;
}