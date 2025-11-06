/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmpInt(const void *a, const void *b){
    return *(int*)a-*(int*)b;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize,sizeof(int), cmpInt);
    int **ans=malloc(sizeof(int*)*numsSize);
    int *column=calloc(numsSize, sizeof(int));
    int count=0, size=numsSize;
    int *result;
    for(int i=0;i<numsSize-3;i++){
        for(int j=i+1;j<numsSize-2;j++){
            long long newTarget=(long long)target-(long long)nums[i]-(long long)nums[j];
            int left=j+1, right=numsSize-1;
            while(left<right){
                int sum=nums[left]+nums[right];
                if(sum>newTarget){
                    right--;
                }
                else if(sum<newTarget){
                    left++;
                }
                else{
                    result=malloc(sizeof(int)*4);
                    result[0]=nums[i];
                    result[1]=nums[j];
                    result[2]=nums[left];
                    result[3]=nums[right];
                    column[count]=4;
                    ans[count++]=result;
                    // number of triplets may be larger than 'size'
                    if(count==size){
                        size *= 2;
                        ans=realloc(ans, sizeof(int*)*size);
                        column=realloc(column, sizeof(int)*size);
                    }
                    left++;
                    right--;
                    while(left<right && nums[left]==nums[left-1]){
                        left++;
                    }
                    while(left<right && nums[right]==nums[right+1]){
                        right--;
                    }
                }
            }
            // Skip same numbers
            while(j+1<numsSize && nums[j]==nums[j+1]){
                j++;
            }
        }
        // Skip same numbers
        while(i+1<numsSize && nums[i]==nums[i+1]){
            i++;
        }
    }
    (*returnSize)=count;
    (*returnColumnSizes)=column;
    return ans;
}