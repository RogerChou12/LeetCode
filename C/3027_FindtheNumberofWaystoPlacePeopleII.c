#include<limits.h>
#include<stdlib.h>

int cmpIntxy(const void *a, const void *b){
    int* pa=*(int**)a;
    int* pb=*(int**)b;
    if(pa[0]==pb[0]){
        return pb[1]-pa[1];
    }
    return pa[0]-pb[0];
}
int numberOfPairs(int** points, int pointsSize, int* pointsColSize) {
    qsort(points, pointsSize, sizeof(int*), cmpIntxy);
    int count=0;
    for(int i=0;i<pointsSize;i++){
        int min_y=INT_MIN;
        for(int j=i+1;j<pointsSize;j++){
            if(points[i][1]>=points[j][1]){
                if(points[j][1]>min_y){
                    min_y=points[j][1];
                    count++;
                }
            }
        }
    }
    return count;
}