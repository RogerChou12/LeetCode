/*
 * // This is the definition for customFunction API.
 * // You should not implement it, or speculate about its implementation
 *
 * // Returns f(x, y) for any given positive integers x and y.
 * // Note that f(x, y) is increasing with respect to both x and y.
 * // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findSolution(int (*customFunction)(int, int), int z, int* returnSize, int** returnColumnSizes) {
	int **ans=malloc(sizeof(int*)*1000);
    (*returnColumnSizes)=malloc(sizeof(int)*1000);
    int count=0;
    int y=1000;
    for(int x=1;x<=1000;x++){
        while(y>1 && customFunction(x, y)>z){
            y--;
        }
        if(customFunction(x, y)==z){
            (*returnColumnSizes)[count]=2;
            ans[count]=malloc(sizeof(int)*2);
            ans[count][0]=x;
            ans[count][1]=y;
            count++;
        }
    }
    (*returnSize)=count;
    return ans;
}