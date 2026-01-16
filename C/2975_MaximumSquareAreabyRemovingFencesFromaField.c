int cmpInt(const void *a, const void *b){
    return *(int*)a-*(int*)b;
}

int *getEdges(int *fence, int fenceSize, int border, int *outsize){
    int arrSize=fenceSize+2;
    int *arr=malloc(sizeof(int)*arrSize);
    memcpy(arr, fence, sizeof(int)*fenceSize);
    // Add 1 and m/n to hfence/vfence
    arr[fenceSize]=1;
    arr[fenceSize+1]=border;
    qsort(arr, arrSize, sizeof(int), cmpInt);
    // Difference of fences
    int diffSize=arrSize*(arrSize-1)/2;
    int *diff=malloc(sizeof(int)*diffSize);
    int idx=0;
    for(int i=0;i<arrSize;i++){
        for(int j=i+1;j<arrSize;j++){
            diff[idx++]=arr[j]-arr[i];
        }
    }
    qsort(diff, diffSize, sizeof(int), cmpInt);
    // Eliminate duplicates
    int k=0;
    for(int i=0;i<idx;i++){
        if(i==0 || diff[i]!=diff[i-1]){
            diff[k++]=diff[i];
        }
    }
    free(arr);
    *outsize=k;
    return diff;
}

int maximizeSquareArea(int m, int n, int* hFences, int hFencesSize, int* vFences, int vFencesSize) {
    int hsize=0, vsize=0;
    int *hedges=getEdges(hFences, hFencesSize, m, &hsize);
    int *vedges=getEdges(vFences, vFencesSize, n, &vsize);
    int v=0, h=0, side=0;
    while(v<vsize && h<hsize){
        if(hedges[h]==vedges[v]){
            if(hedges[h]>side){
                side=hedges[h];
            }
            h++;
            v++;
        }
        else if(hedges[h]<vedges[v]){
            h++;
        }
        else{
            v++;
        }
    }
    if(side==0){
        return -1;
    }
    return (int)((long long)side*side%1000000007);
}