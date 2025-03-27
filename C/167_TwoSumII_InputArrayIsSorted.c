/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int* ans = malloc(sizeof(int)*2);
    int left=0, right=numbersSize-1;

    while(left < right){
        int sum = numbers[left]+numbers[right];
        if(sum == target){
            ans[0] = left+1;
            ans[1] = right+1;
            break;
        }
        else if(sum < target){
            left++;
        }
        else{
            right--;
        }
    }

    (*returnSize) = 2;
    return ans;
}