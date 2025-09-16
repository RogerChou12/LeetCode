/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int fGCD(int a, int b){
    return a?fGCD(b%a, a):b;
}

int* replaceNonCoprimes(int* nums, int numsSize, int* returnSize) {
    int *stack=malloc(sizeof(int)*numsSize);
    int top=0;
    for(int i=0;i<numsSize;i++){
        int cur=nums[i];
        while(top>0){
            int prev=stack[top-1];
            int gcd=fGCD(prev, cur);
            if(gcd==1){
                break;
            }
            top--;
            cur=(prev/gcd)*cur;
        }
        stack[top++]=cur;
    }
    (*returnSize)=top;
    return stack;
}