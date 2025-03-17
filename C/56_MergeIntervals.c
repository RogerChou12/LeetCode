/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include<stdbool.h>

int cmpInterval(const void *a, const void *b){
    int *interval_a = *(const int**) a;
    int *interval_b = *(const int**) b;
    if(interval_a[0]==interval_b[0]) return interval_a[1]-interval_b[1];
    return interval_a[0]-interval_b[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    int **ans = malloc(sizeof(int*)*intervalsSize);
    int *temp = malloc(sizeof(int)*2);
    bool exist = 0; // merged interval exist or not
    qsort(intervals, intervalsSize, sizeof(int*), cmpInterval); // 'intervals' is sorted by end
    int count = 0;
    int *columns = malloc(sizeof(int)*intervalsSize);

    for(int i=0;i<intervalsSize;i++){
        if(!exist){
            temp = intervals[i];
            exist = 1;
        }
        else{
            if(intervals[i][0] <= temp[1]){
                exist = 1;
                temp[1] = fmax(intervals[i][1], temp[1]);
            }
            else{
                columns[count] = 2;
                ans[count++] = temp;
                exist = 0;
                i--;
            }
        }
    }
    // the last merged interval
    columns[count] = 2;
    ans[count++] = temp;
    (*returnSize) = count;
    (*returnColumnSizes) = columns;
    return ans;
}