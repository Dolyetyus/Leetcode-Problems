bool isRowValid (char** board) {
    for (int i = 0; i<9; i++) {
        int* hmap = calloc(10, sizeof(int));
        for (int ii = 0; ii<9; ii++) {
            if (board[i][ii] == '.') continue;
            if (hmap[board[i][ii]-48] != 0) return false;
            hmap[board[i][ii]-48] = 1;
        }
        free(hmap);
    }

    return true;
}

bool isColValid (char** board) {
    for (int i = 0; i<9; i++) {
        int* hmap = calloc(10, sizeof(int));
        for (int ii = 0; ii<9; ii++) {
            if (board[ii][i] == '.') continue;
            if (hmap[board[ii][i]-48] != 0) return false;
            hmap[board[ii][i]-48] = 1;
        }
        free(hmap);
    }

    return true;
}

bool isBoxValid (char** board, int x, int y) {
    int* hmap = calloc(10, sizeof(int));

    for (int i = 0; i<3; i++) {
        for (int ii = 0; ii<3; ii++) {
            if (board[x+i][y+ii] == '.') continue;
            if (hmap[board[x+i][y+ii]-48] != 0) return false;
            hmap[board[x+i][y+ii]-48] = 1;
        }
    }

    free(hmap);
    return true;
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    
    for (int i = 0; i<9; i+=3) {
        for (int ii = 0; ii<9; ii+=3) {
            if (!isBoxValid(board, i, ii)) return false;
        }
    }

    return isRowValid(board) && isColValid(board);
}
