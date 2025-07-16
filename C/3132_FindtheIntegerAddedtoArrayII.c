#include<stdbool.h>
#include<limits.h>

int cmpInt(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

bool check(int* nums1, int nums1Size, int* nums2, int nums2Size, int diff){
    int notEqual=0;
    for(int id1=0, id2=0;id1<nums1Size && id2<nums2Size;id1++){
        if(nums1[id1]+diff != nums2[id2]){
            notEqual++;
        }
        else{
            id2++;
        }

        if(notEqual > 2){
            return false;
        }
    }
    return true;
}

int minimumAddedInteger(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int minDiff=INT_MAX;

    qsort(nums1, nums1Size, sizeof(int), cmpInt);
    qsort(nums2, nums2Size, sizeof(int), cmpInt);

    for(int id1=0;id1<3;id1++){
        int diff = nums2[0]-nums1[id1];
        if(check(nums1, nums1Size, nums2, nums2Size, diff)){
            minDiff = fmin(diff, minDiff);
        }
    }
    return minDiff;
}