int countTriplets(int* arr, int arrSize) {
    int ans=0;

    for(int i=0;i<arrSize;i++){
        int temp = arr[i];
        for(int k=i+1;k<arrSize;k++){
            temp ^= arr[k];
            if(temp == 0){
                ans += (k-i);
            }
        }
    }
    return ans;
}