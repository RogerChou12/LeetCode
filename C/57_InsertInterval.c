/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    int count = 0; // total number of intervals
    int **ans = malloc(sizeof(int*)*(intervalsSize+1));
    int *column = malloc(sizeof(int)*(intervalsSize+1));

    if(intervalsSize==0){
        (*returnSize) = 1;
        ans[0] = newInterval;
        column[0] = 2;
        (*returnColumnSizes) = column;
        return ans;
    }

    int overlap = -1;
    for(int i=0;i<intervalsSize;i++){
        if(newInterval[0] <= intervals[i][1]){
            overlap = i;
            break;
        }
        else{
            column[count] = 2;
            ans[count] = malloc(sizeof(int)*2);
            ans[count++] = intervals[i];
        }
    }

    if(overlap != -1){
        for(int i=overlap;i<intervalsSize;i++){
            if(newInterval[1] >= intervals[i][0]){
                newInterval[0] = fmin(newInterval[0], intervals[i][0]);
                newInterval[1] = fmax(newInterval[1], intervals[i][1]);
            }
            else{
                column[count] = 2;
                ans[count] = malloc(sizeof(int)*2);
                ans[count++] = newInterval;
                newInterval = intervals[i];
            }
        }
    }
    
    column[count] = 2;
    ans[count] = malloc(sizeof(int)*2);
    ans[count++] = newInterval;

    (*returnSize) = count;
    (*returnColumnSizes) = column;
    return ans;
}