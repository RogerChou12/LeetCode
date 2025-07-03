int countSetBits(int num){
    int count=0;
    while(num){
        count += (num & 1);
        num >>= 1;
    }
    return count;
}
int minimizeXor(int num1, int num2) {
    int setbits1=countSetBits(num1);
    int setbits2=countSetBits(num2);
    int ans = num1;
    for(int i=0;i<32;i++){
        if((setbits1 > setbits2) && ((1<<i)&num1)){
            ans ^= (1<<i);
            setbits1--;
        }
        if((setbits1 < setbits2) && !((1<<i)&num1)){
            ans ^= (1<<i);
            setbits1++;
        }
    }
    return ans;
}