int hammingWeight(int n) {
    int setbits = 0;
    while(n>0){
        setbits += (1&n);
        n = n>>1;
    }
    return setbits;
}