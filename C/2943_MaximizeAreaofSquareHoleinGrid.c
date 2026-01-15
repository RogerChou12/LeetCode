int cmpInt(const void *a, const void *b){
    return *(int*)a-*(int*)b;
}

int maximizeSquareHoleArea(int n, int m, int* hBars, int hBarsSize, int* vBars, int vBarsSize) {
    qsort(hBars, hBarsSize, sizeof(int), cmpInt);
    qsort(vBars, vBarsSize, sizeof(int), cmpInt);
    int vCur=1, hCur=1;
    int vMax=1, hMax=1;
    for(int i=1;i<hBarsSize;i++){
        if(hBars[i]==hBars[i-1]+1){
            hCur++;
        }
        else{
            hCur=1;
        }
        hMax=fmax(hCur, hMax);
    }
    for(int i=1;i<vBarsSize;i++){
        if(vBars[i]==vBars[i-1]+1){
            vCur++;
        }
        else{
            vCur=1;
        }
        vMax=fmax(vCur, vMax);
    }
    int side=1+fmin(hMax, vMax);
    return side*side;
}