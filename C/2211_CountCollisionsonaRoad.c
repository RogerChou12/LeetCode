int countCollisions(char* directions) {
    int len=strlen(directions);
    int left=0, right=len-1, ans=0;
    while(left<len && directions[left]=='L'){
        left++;
    }
    while(right>=left && directions[right]=='R'){
        right--;
    }
    for(int i=left;i<=right;i++){
        if(directions[i]!='S'){
            ans++;
        }
    }
    return ans;
}