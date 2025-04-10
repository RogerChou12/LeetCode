/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void flip(int *arr, int k){
    int i=0, j=k-1;
    while(i<j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

int findMax(int *arr, int k){
    int idx=0;
    while(arr[idx] != k){
        idx++;
    }
    return idx;
}

int* pancakeSort(int* arr, int arrSize, int* returnSize) {
    int *ans = malloc(sizeof(int)*arrSize*2);
    int idx=0;

    for(int currSize=arrSize;currSize>1;currSize--){
        // Find the index of the max element in arr[0...currSize-1]
        int max_idx = findMax(arr, currSize);
        if(max_idx+1 != currSize){
            // Flip max element to front if not already at index 0
            if(max_idx != 0){
                flip(arr, max_idx+1);
                ans[idx++] = max_idx+1;
            }
            // Flip it to the correct position at end of current size
            flip(arr, currSize);
            ans[idx++] = currSize;
        }
    }
    (*returnSize) = idx;
    return ans;
}