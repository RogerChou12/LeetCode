int GCD(int a, int b){
    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

int minOperations(int* nums, int numsSize) {
    int allGCD=0, one=0, minLen=numsSize;
    for(int i=0;i<numsSize;i++){
        if(nums[i]==1){
            one++;
        }
        allGCD=GCD(nums[i], allGCD);
    }
    if(one>0){
        return numsSize-one;
    }
    if(allGCD>1){
        return -1;
    }
    for(int i=0;i<numsSize;i++){
        int curGCD=0;
        for(int j=i;j<numsSize;j++){
            curGCD=GCD(nums[j], curGCD);
            if(curGCD==1){
                if(j-i+1<minLen){
                    minLen=j-i+1;
                }
                break;
            }
        }
    }
    return minLen+numsSize-2;
}