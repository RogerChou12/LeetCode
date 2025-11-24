int maxDivScore(int* nums, int numsSize, int* divisors, int divisorsSize) {
    int divisor=divisors[0], max_score=0;
    for(int i=0;i<divisorsSize;i++){
        int score=0;
        for(int j=0;j<numsSize;j++){
            if(nums[j]%divisors[i]==0){
                score++;
            }
        }
        if(score>max_score){
            max_score=score;
            divisor=divisors[i];
        }
        else if(score==max_score){
            divisor=fmin(divisor, divisors[i]);
        }
    }
    return divisor;
}