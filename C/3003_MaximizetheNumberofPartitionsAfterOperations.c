int maxPartitionsAfterOperations(char* s, int k) {
    int n=strlen(s);
    int **left=malloc(sizeof(int*)*n);
    int **right=malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++){
        left[i]=calloc(3, sizeof(int));
        right[i]=calloc(3, sizeof(int));
    }
    // Left split
    int splits=0, mask=0, distinct=0;
    for(int i=0;i<n-1;i++){
        int binary=1<<(s[i]-'a');
        // Distinct character
        if(!(mask&binary)){
            distinct++;
            if(distinct<=k){
                mask |= binary;
            }
            else{
                splits++;
                mask=binary;
                distinct=1;
            }
        }
        left[i+1][0]=splits;
        left[i+1][1]=mask;
        left[i+1][2]=distinct;
    }
    // Right split
    splits=0, mask=0, distinct=0;
    for(int i=n-1;i>0;i--){
        int binary=1<<(s[i]-'a');
        // Distinct character
        if(!(mask&binary)){
            distinct++;
            if(distinct<=k){
                mask |= binary;
            }
            else{
                splits++;
                mask=binary;
                distinct=1;
            }
        }
        right[i-1][0]=splits;
        right[i-1][1]=mask;
        right[i-1][2]=distinct;
    }
    // Total partitions
    int max=0;
    for(int i=0;i<n;i++){
        int part=left[i][0]+right[i][0]+2; // (left+1)+(right+1)
        int totalMask=left[i][1] | right[i][1];
        int totalDistinct=0;
        while(totalMask){
            totalMask=totalMask&(totalMask-1);
            totalDistinct++;
        }
        if(left[i][2]==k && right[i][2]==k && totalDistinct<26){
            part++;
        }
        else{
            int minDistinct=fmin(totalDistinct+1, 26);
            if(minDistinct<=k){
                part--;
            }
        }
        max=fmax(max, part);
    }
    for(int i=0;i<n;i++){
        free(left[i]);
        free(right[i]);
    }
    free(left);
    free(right);
    return max;
}