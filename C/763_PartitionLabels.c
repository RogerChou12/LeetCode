/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* partitionLabels(char* s, int* returnSize) {
    int *ans = malloc(sizeof(int)*26);
    int *lastPosition = malloc(sizeof(int)*26);
    int slen = strlen(s);

    // Record the last position of each character in the string
    for(int i=0;i<slen;i++){
        lastPosition[s[i]-'a'] = i;
    }

    int endPartition=0, start=0, part=0;
    for(int current=0;current<slen;current++){
        endPartition = fmax(endPartition, lastPosition[s[current]-'a']);
        // Find the end of the partition
        if(current==endPartition){
            ans[part++] = endPartition-start+1;
            start = current+1;
        }
    }

    free(lastPosition);
    (*returnSize) = part;
    return ans;
}