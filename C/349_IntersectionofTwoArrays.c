/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdbool.h>

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    bool *hashTable = calloc(sizeof(bool), 1001);
    int *intersection = malloc(sizeof(int)*((nums1Size>nums2Size ? nums1Size:nums2Size)+1));
    int idx = 0;

    for(int i=0;i<nums1Size;i++){
        hashTable[nums1[i]] = 1;
    }

    for(int i=0;i<nums2Size;i++){
        if(hashTable[nums2[i]]){
            intersection[idx++] = nums2[i];
            hashTable[nums2[i]] = 0; // Prevent duplicates
        }
    }
    (*returnSize) = idx;
    return intersection;
}
