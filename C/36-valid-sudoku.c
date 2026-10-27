bool areRowsValid(char** board, int boardSize) {
    for(int i = 0; i < boardSize; i++){
        bool seen[10] = {0};

        for(int j = 0; j < boardSize; j++){
            char cell = board[i][j];

            if (cell == '.') continue;

            if(!seen[cell - '1'])
                seen[cell - '1'] = 1;
            else
                return 0;
        }
    }

    return 1;
}

bool areColumnsValid(char** board, int boardSize) {
    for (int j = 0; j < boardSize; j++) {
        bool seen[10] = {0};

        for (int i = 0; i < boardSize; i++) {
            char cell = board[i][j];

            if (cell == '.') continue;

            if (!seen[cell - '1'])
                seen[cell - '1'] = 1;
            else
                return 0;
        }
    }

    return 1;
}

bool areBoxesValid(char** board) {
    const int BOX_SIZE = 3;

    for (int box = 0; box < 9; box++) {
        bool seen[10] = {0};

        int rowOffset = (box / BOX_SIZE) * BOX_SIZE;
        int colOffset = (box % BOX_SIZE) * BOX_SIZE;

        for (int i = 0; i < 9; i++) {
            int row = rowOffset + i / BOX_SIZE;
            int col = colOffset + i % BOX_SIZE;

            char cell = board[row][col];

            if (cell == '.') continue;

            int digit = cell - '1';

            if (seen[digit]) return 0;

            seen[digit] = 1;
        }
    }

    return 1;
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    return areRowsValid(board, boardSize) &&
           areColumnsValid(board, boardSize) &&
           areBoxesValid(board);
}
