/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minBitwiseArray(int* nums, int numsSize, int* returnSize) {
    for(int i=0;i<numsSize;i++){
        int x=nums[i];
        int ans=-1;
        int d=1;
        while((x&d)!=0){
            ans=x-d;
            d<<=1;
        }
        nums[i]=ans;
    }
    (*returnSize)=numsSize;
    return nums;
}