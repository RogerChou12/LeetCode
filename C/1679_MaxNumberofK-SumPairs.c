int maxOperations(int* nums, int numsSize, int k){
    int pairs=0;
    int *possible_pair = calloc(sizeof(int), (k+1));

    for(int i=0;i<numsSize;i++){
        if(nums[i] < k){
            int target=k-nums[i];
            // If there's no match for current nums[i], store it as a potential pair
            if(possible_pair[target] == 0){
                possible_pair[nums[i]]++;
            }
            else{
                pairs++; // A matching value was seen earlie
                possible_pair[target]--; // Use up one occurrence of the complement
            }
        }
    }

    return pairs;
}