int findSmallestInteger(int* nums, int numsSize, int value) {
    int *remainders=calloc(value, sizeof(int));
    int mex=0;
    for(int i=0;i<numsSize;i++){
        int rem=(nums[i]%value + value)%value; // Handle negatives
        remainders[rem]++;
    }
    while(remainders[mex%value]>0){
        remainders[mex%value]--;
        mex++;
    }
    return mex;
}