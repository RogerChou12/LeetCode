#include<stdbool.h>

bool areSimilar(int** mat, int matSize, int* matColSize, int k) {
    k=k%(*matColSize);
    for(int row=0;row<matSize;row++){
        for(int col=0;col<(*matColSize);col++){
            if(mat[row][col]!=mat[row][(col+k)%(*matColSize)]){
                return false;
            }
        }
    }
    return true;
}