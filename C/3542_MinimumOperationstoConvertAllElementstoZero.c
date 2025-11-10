int minOperations(int* nums, int numsSize) {
    int *stack=malloc(sizeof(int)*numsSize);
    int top=0, operation=0;
    for(int i=0;i<numsSize;i++){
        int value=nums[i];
        while(top>0 && stack[top-1]>value){
            top--;
        }
        if(value==0){
            continue;
        }
        if(top==0 || stack[top-1]<value){
            operation++;
            stack[top++]=value;
        }
    }
    return operation;
}