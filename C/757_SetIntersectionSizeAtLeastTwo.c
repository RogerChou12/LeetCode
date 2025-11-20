#include<stdbool.h>

int cmpInterval(const void *a, const void *b){
    int *ta=*(int**)a;
    int *tb=*(int**)b;
    if(ta[1]==tb[1]) return tb[0]-ta[0];
    return ta[1]-tb[1];
}

int intersectionSizeTwo(int** intervals, int intervalsSize, int* intervalsColSize) {
    qsort(intervals, intervalsSize, sizeof(int*), cmpInterval);
    int ans=0, largest1=-1, largest2=-1;
    for(int i=0;i<intervalsSize;i++){
        int start=intervals[i][0];
        int end=intervals[i][1];
        bool largest1_in=(start<=largest1);
        bool largest2_in=(start<=largest2);
        if(largest1_in && largest2_in) continue;
        ans+=(largest1_in?1:2);
        largest2=largest1_in?largest1:end-1;
        largest1=end;
    }
    return ans;
}