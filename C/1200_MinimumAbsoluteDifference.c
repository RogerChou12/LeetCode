/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmpInt(const void *a, const void *b){
    return *(int*)a-*(int*)b;
}

int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes) {
    qsort(arr, arrSize, sizeof(int), cmpInt);
    int **ans=malloc(sizeof(int*)*arrSize);
    int *column=malloc(sizeof(int)*arrSize);
    int count=0;
    int minDiff=arr[arrSize-1]-arr[0];
    for(int i=1;i<arrSize;i++){
        int diff=arr[i]-arr[i-1];
        if(diff<minDiff){
            minDiff=diff;
            count=0;
            ans[count]=malloc(sizeof(int)*2);
            column[count]=2;
            ans[count][0]=arr[i-1];
            ans[count][1]=arr[i];
            count++;
        }
        else if(diff==minDiff){
            ans[count]=malloc(sizeof(int)*2);
            column[count]=2;
            ans[count][0]=arr[i-1];
            ans[count][1]=arr[i];
            count++;
        }
    }
    (*returnSize)=count;
    (*returnColumnSizes)=column;
    return ans;
}