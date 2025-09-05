int makeTheIntegerZero(int num1, int num2) {
    int k=1;
    long long x=(long long)num1-k*(long long)num2;
    int count=0;
    while(x>=k){
        int bits=0;
        while(x>0){
            bits+=(x&1);
            x>>=1;
        }
        if(k>=bits){
            return k;
        }
        k++;
        x=(long long)num1-k*(long long)num2;
    }
    return -1;
}