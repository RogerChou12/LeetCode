/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructTransformedArray(int* nums, int numsSize, int* returnSize) {
    int *result=malloc(sizeof(int)*numsSize);
    for(int i=0;i<numsSize;i++){
        if(nums[i]>0){
            int step=nums[i]%numsSize;
            result[i]=nums[(i+step)%numsSize];
        }
        else if(nums[i]<0){
            int step=(-nums[i])%numsSize;
            result[i]=nums[(i-step+numsSize)%numsSize];
        }
        else{
            result[i]=nums[i];
        }
    }
    (*returnSize)=numsSize;
    return result;
}