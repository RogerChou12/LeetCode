int smallestNumber(int n) {
    while((n & (n+1)) != 0){
        n = n | (n>>1); // set bits to the right of the highest set bit
    }
    return n;
}