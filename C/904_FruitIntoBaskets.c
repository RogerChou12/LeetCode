int totalFruit(int* fruits, int fruitsSize) {
    int baskets=0, count=0, left=0, right=0, ans=0;
    int freq[100001]={0};

    for(left=0,right=0;right<fruitsSize;right++){
        if(++freq[fruits[right]]==1){
            baskets++;
        }
        count++;
        while(baskets>2){
            if(--freq[fruits[left]]==0){
                baskets--;
            }
            left++;
            count--;
        }
        ans=fmax(ans, count);
    }
    return ans;
}