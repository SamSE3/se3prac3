#include <stdio.h>
#include <stdlib.h>
#include "2048.h"
#include <string.h>

int **board_create(int size) {
    int i;
    // make sure size of board is sensible
    if (size < 1 || size > 255) return NULL;

    int **board = calloc(size, sizeof (int *));
    if (!board) return NULL;
    for (i = 0; i < size; i++) {
        board[i] = calloc(size, sizeof (int));
        if (!board[i]) return NULL;
    }
    return board;
}

int board_display(int size, int **board) {
    // make sure size of board is sensible
    if (size < 1 || size > 255) return -1;

    int x, y;

    for (y = 0; y < size; y++) {
        for (x = 0; x < size; x++) {
            if (board[x][y]) printf("[% 5d]", board[x][y]);
            else printf("[     ]");
        }
        printf("\n");
    }
    return 0;
}

int ** boardCopy(int size, int **board) {
    if (size < 1 || size > 255) NULL;
    int **boardCopy = board_create(size);
    memcpy(boardCopy, board, size * size);
    /* int x,y;
      for(y=0;y<size;y++) {    
      for(x=0;x<size;x++) {
          boardCopy[x][y]
      }
      }*/
    return boardCopy;
}