/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmpInt(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize) {
    int *successful = malloc(sizeof(int)*spellsSize);
    qsort(potions, potionsSize, sizeof(int), cmpInt);

    for(int i=0;i<spellsSize;i++){
        int left=0, right=potionsSize-1;
        long long product=0;
        while(left <= right){
            int mid = left+(right-left)/2;
            product = (long long)spells[i] * (long long)potions[mid];
            if(product >= success){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        successful[i] = potionsSize-left;
    }

    (*returnSize) = spellsSize;
    return successful;
}