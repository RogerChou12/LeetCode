/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void backtrack(char* s, int* returnSize, int cur_idx, char** ans){
    if(s[cur_idx]=='\0'){
        ans[(*returnSize)++] = strdup(s);
        return;
    }
    backtrack(s, returnSize, cur_idx+1, ans);

    if(isalpha(s[cur_idx])){
        s[cur_idx] ^= 32; // ASCII difference between uppercase and lowercase letters is 32. 'a'^32='A'
        backtrack(s, returnSize, cur_idx+1, ans);
        s[cur_idx] ^= 32;
    }
}

char** letterCasePermutation(char* s, int* returnSize) {
    (*returnSize) = 0;
    char** ans = malloc(sizeof(char*)*(1<<strlen(s)));
    backtrack(s, returnSize, 0, ans);
    return ans;
}