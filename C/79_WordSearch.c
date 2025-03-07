bool search(char** board, int boardSize, int* boardColSize, char* word, int i, int j){
    if(strlen(word)<=0) return true;
    if(i<0 || i>=boardSize || j<0 || j>=boardColSize[i]) return false;
    if(board[i][j] != word[0]) return false;

    char temp = board[i][j];
    board[i][j] = '1'; // visited
    bool existed = (search(board, boardSize, boardColSize, &word[1], i+1, j) ||
                  search(board, boardSize, boardColSize, &word[1], i-1, j) ||
                  search(board, boardSize, boardColSize, &word[1], i, j+1) ||
                  search(board, boardSize, boardColSize, &word[1], i, j-1));
    board[i][j] = temp;
    return existed;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardColSize[i];j++){
            if(search(board, boardSize, boardColSize, word, i, j)) return true;
        }
    }
    return false;
}