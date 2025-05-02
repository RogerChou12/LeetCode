/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes) {
    int left=0, right=imageColSize[0]-1;
    // Flip horizontally
    while(left <= right){
        for(int row=0;row<imageSize;row++){
            int temp = image[row][left] ^ 1; // Invert
            image[row][left] = image[row][right] ^ 1; // Invert
            image[row][right] = temp;
        }
        left++;
        right--;
    }
    
    (*returnSize) = imageSize;
    (*returnColumnSizes) = imageColSize;
    return image;
}