int findClosest(int x, int y, int z) {
    int d1=abs(z-x), d2=abs(y-z);
    if(d1>d2){
        return 2;
    }
    else if(d1<d2){
        return 1;
    }
    return 0;
}