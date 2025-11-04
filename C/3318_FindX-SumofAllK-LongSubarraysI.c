/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct{
    int num;
    int freq;
} Pair;

int cmpPair(const void *a, const void *b){
    Pair *pa=(Pair*)a;
    Pair *pb=(Pair*)b;
    if(pa->freq != pb->freq){
        return pb->freq-pa->freq;
    }
    return pb->num-pa->num;
}

int* findXSum(int* nums, int numsSize, int k, int x, int* returnSize) {
    (*returnSize)=numsSize-k+1;
    int *ans=malloc(sizeof(int)*(*returnSize));
    int freq[51]={0};
    for(int i=0;i<k;i++){
        freq[nums[i]]++;
    }
    for(int i=0;i<numsSize-k+1;i++){
        Pair numFreq[51];
        int count=0;
        for(int number=1;number<51;number++){
            if(freq[number]>0){
                numFreq[count].num=number;
                numFreq[count].freq=freq[number];
                count++;
            }
        }
        qsort(numFreq, count, sizeof(Pair), cmpPair);
        int sum=0;
        for(int j=0;j<count&&j<x;j++){
            sum+=numFreq[j].num * numFreq[j].freq;
        }
        ans[i]=sum;
        // slide window for one step
        if(i+k<numsSize){
            freq[nums[i]]--;
            freq[nums[i+k]]++;
        }
    }
    return ans;
}