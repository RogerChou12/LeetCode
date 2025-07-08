long long minEnd(int n, int x) {
    long long ans=x;
    int remain=n-1;
    long long position=1;

    while(remain){
        if(!(x & position)){
            ans |= (remain & 1)*position;
            remain >>= 1;
        }
        position <<= 1;
    }
    return ans;
}