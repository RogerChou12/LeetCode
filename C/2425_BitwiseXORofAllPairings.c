int xorAllNums(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int ans = 0;
    if(nums1Size%2){
        for(int i=0;i<nums2Size;i++){
            ans ^= nums2[i];
        }
    }
    if(nums2Size%2){
        for(int i=0;i<nums1Size;i++){
            ans ^= nums1[i];
        }
    }

    return ans;
}