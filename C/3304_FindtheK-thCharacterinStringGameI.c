char kthCharacter(int k) {
    int oneBits=0;
    k -= 1;
    while(k>0){
        oneBits += (k&1);
        k >>= 1;
    }
    return 'a'+oneBits;
}