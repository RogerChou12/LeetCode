/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pivotArray(int* nums, int numsSize, int pivot, int* returnSize) {
    int *ans = malloc(sizeof(int)*numsSize);
    int *equal =  malloc(sizeof(int)*numsSize);
    int *greater =  malloc(sizeof(int)*numsSize);
    int pos=0, same=0, big=0;

    for(int i=0;i<numsSize;i++){
        if(nums[i] < pivot){
            ans[pos++] = nums[i];
        }
        else if(nums[i] > pivot){
            greater[big++] = nums[i];
        }
        else{
            equal[same++] = nums[i];
        }
    }
    memcpy(ans+pos, equal, same*sizeof(int));
    memcpy(ans+pos+same, greater, big*sizeof(int));
    
    free(equal);
    free(greater);
    (*returnSize) = numsSize;
    return ans;
}