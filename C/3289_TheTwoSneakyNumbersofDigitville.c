/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getSneakyNumbers(int* nums, int numsSize, int* returnSize) {
    int xor=0;
    int *ans=malloc(sizeof(int)*2);
    for(int i=0;i<numsSize;i++){
        xor^=nums[i];
    }
    for(int i=0;i<numsSize-2;i++){
        xor^=i;
    }

    int lowbit=xor & (-xor); // The lowest position where a and b differ
    int x1=0, x2=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]&lowbit){
            x1^=nums[i];
        }
        else{
            x2^=nums[i];
        }
    }
    for(int i=0;i<numsSize-2;i++){
        if(i&lowbit){
            x1^=i;
        }
        else{
            x2^=i;
        }
    }
    (*returnSize)=2;
    ans[0]=x1;
    ans[1]=x2;
    return ans;
}