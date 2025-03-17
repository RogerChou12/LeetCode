/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmpInt(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int size=numsSize; // size of answer
    int count=0;
    int **ans=malloc(sizeof(int*)*size);
    int *column=malloc(sizeof(int)*size);
    int *triplet; // store the triplet we found
    qsort(nums, numsSize, sizeof(int), cmpInt);

    // first number of triplet
    for(int i=0;i<numsSize-2;i++){
        if(nums[i]>0){
            break; // sum always >0
        }
        if(i>0 && nums[i]==nums[i-1]){
            continue;// same first number
        }

        // 2 pointers for 2-sum problem
        int left=i+1, right=numsSize-1;
        while(left<right){
            int sum=nums[i]+nums[left]+nums[right];
            if(sum>0){
                right--;
            }
            else if(sum<0){
                left++;
            }
            else{
                triplet=malloc(sizeof(int)*3);
                triplet[0]=nums[i];
                triplet[1]=nums[left];
                triplet[2]=nums[right];
                column[count]=3;
                ans[count++]=triplet;

                // number of triplets may be larger than 'size'
                if(count==size){
                    size *= 2;
                    ans=realloc(ans, sizeof(int*)*size);
                    column=realloc(column, sizeof(int)*size);
                }

                //move to next (left, right)
                left++;
                right--;
                // skip same numbers
                while(left<right && nums[left]==nums[left-1]){
                    left++;
                }
                while(left<right && nums[right]==nums[right+1]){
                    right--;
                }
            }
        }
    }
    (*returnSize)=count;
    (*returnColumnSizes)=column;
    return ans;
}