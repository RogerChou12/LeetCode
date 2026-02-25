/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int countBit(int n){
    int count=0;
    while(n>0){
        n&=(n-1);
        count++;
    }
    return count;
}

int cmpBitCount(const void *a, const void *b){
    int int_a=*(const int*)a;
    int int_b=*(const int*)b;
    int count_a=countBit(int_a);
    int count_b=countBit(int_b);
    if(count_a!=count_b){
        return count_a-count_b;
    }
    return int_a-int_b;
}

int* sortByBits(int* arr, int arrSize, int* returnSize) {
    qsort(arr, arrSize, sizeof(int), cmpBitCount);
    (*returnSize)=arrSize;
    return arr;
}