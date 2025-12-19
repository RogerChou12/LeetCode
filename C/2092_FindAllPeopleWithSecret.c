/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int findSource(int *group, int value){
    // Find the source of 'value'
    while(value!=group[value]){
        value=group[value];
    }
    return value;
}

int cmpInt(const void *a, const void *b){
    int *ma=*(int**)a;
    int *mb=*(int**)b;
    return ma[2]-mb[2];
}

int* findAllPeople(int n, int** meetings, int meetingsSize, int* meetingsColSize, int firstPerson, int* returnSize) {
    int *ans=malloc(sizeof(int)*n);
    int ans_idx=0;
    int *group=malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        group[i]=i;
    }
    group[firstPerson]=0;
    qsort(meetings, meetingsSize, sizeof(int*), cmpInt);
    int *sameTime=malloc(sizeof(int)*(2*n));
    int i=0;
    while(i<meetingsSize){
        int curTime=meetings[i][2];
        int same=0;
        while(i<meetingsSize && meetings[i][2]==curTime){
            int source1=findSource(group, meetings[i][0]);
            int source2=findSource(group, meetings[i][1]);
            group[source1>source2?source1:source2]=source1<source2?source1:source2; // unite
            sameTime[same++]=meetings[i][0];
            sameTime[same++]=meetings[i][1];
            i++;
        }
        // Disunite
        for(int j=0;j<same;j++){
            if(findSource(group, sameTime[j])!=0){
                group[sameTime[j]]=sameTime[j];
            }
        }
    }
    for(int person=0;person<n;person++){
        // Connect to '0'
        if(findSource(group, person)==0){
            ans[ans_idx++]=person;
        }
    }

    free(sameTime);
    free(group);

    (*returnSize)=ans_idx;
    return ans;
}