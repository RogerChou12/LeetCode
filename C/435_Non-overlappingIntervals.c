int cmpEnd(const void *a, const void *b){
    int* interval_a = *(const int**) a;
    int* interval_b = *(const int**) b;
    return interval_a[1]-interval_b[1];
}
int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    // sort interval based on ends
    qsort(intervals, intervalsSize, sizeof(int*), cmpEnd);
    // the 1st inetrval is considered as non-overlapping
    int non_overlap=1, previous=0;
    for(int i=1;i<intervalsSize;i++){
        if(intervals[i][0] >= intervals[previous][1]){
            non_overlap++;
            previous = i;
        }
    }
    return intervalsSize-non_overlap;
}