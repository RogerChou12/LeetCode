/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rearrangeArray(int* nums, int numsSize, int* returnSize) {
    int *ans = malloc(sizeof(int)*numsSize);
    int positive=0, negative=1;

    for(int i=0;i<numsSize;i++){
        if(nums[i]>0){
            ans[positive] = nums[i];
            positive += 2;
        }
        else{
            ans[negative] = nums[i];
            negative += 2;
        }
    }

    (*returnSize) = numsSize;
    return ans;
}