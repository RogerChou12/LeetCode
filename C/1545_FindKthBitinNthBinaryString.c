char findKthBit(int n, int k) {
    int invert=0;
    int length=(1<<n)-1;
    while(k>1){
        if(k==length/2+1){
            return (invert%2==0)?'1':'0';
        }
        if(k>length/2){
            k=length+1-k;
            invert++;
        }
        length/=2;
    }
    return (invert%2==0)?'0':'1';
}