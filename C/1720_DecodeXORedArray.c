/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decode(int* encoded, int encodedSize, int first, int* returnSize) {
    int *ans = malloc(sizeof(int)*(encodedSize+1));
    ans[0] = first;

    for(int i=0;i<encodedSize;i++){
        ans[i+1] = ans[i] ^ encoded[i];
    }

    (*returnSize) = encodedSize+1;
    return ans;
}