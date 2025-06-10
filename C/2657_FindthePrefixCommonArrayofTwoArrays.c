/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findThePrefixCommonArray(int* A, int ASize, int* B, int BSize, int* returnSize) {
    int *C = malloc(sizeof(int)*ASize);
    int *freq = calloc((ASize+1), sizeof(int));
    for(int i=0;i<ASize;i++){
        C[i] = 0;
        freq[A[i]]++;
        freq[B[i]]++;
        if(i==0 && (A[i]==B[i])){
            C[i]++;
        }
        if(i>0){
            if(A[i]==B[i]){
                C[i] = C[i-1]+1;
            }
            else{
                C[i] = C[i-1] + freq[A[i]]/2 + freq[B[i]]/2;
            }
        }
    }
    (*returnSize) = ASize;
    return C;
}