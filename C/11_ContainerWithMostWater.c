int maxArea(int* height, int heightSize){
    int most=0; //  the maximum amount of water
    int left=0, right=heightSize-1;
    while(left<right){
        int water=(right-left)*fmin(height[left], height[right]);
        if(height[left]<height[right]){
            left++;
        }
        else{
            right--;
        }
        most=fmax(most, water);
    }
    return most;
}