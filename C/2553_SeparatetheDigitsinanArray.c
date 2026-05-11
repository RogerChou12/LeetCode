/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* separateDigits(int* nums, int numsSize, int* returnSize) {
    int *ans=malloc(sizeof(int)*6000);
    int total=0;
    for(int i=0;i<numsSize;i++){
        int integer=nums[i];
        int *digits=malloc(sizeof(int)*6);
        int count=0;
        while(integer>0){
            digits[count++]=integer%10;
            integer/=10;
        }
        for(int j=0;j<count;j++){
            ans[total+j]=digits[count-1-j];
        }
        total+=count;
    }
    (*returnSize)=total;
    return ans;
}