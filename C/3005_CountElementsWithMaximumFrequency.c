int maxFrequencyElements(int* nums, int numsSize) {
    int freq[101]={0};
    int maxFreq=0, totalFreq=0;

    for(int i=0;i<numsSize;i++){
        freq[nums[i]]++;
        if(freq[nums[i]]>maxFreq){
            maxFreq=freq[nums[i]];
            totalFreq=maxFreq;
        }
        else if(freq[nums[i]]==maxFreq){
            totalFreq+=maxFreq;
        }
    }
    return totalFreq;
}