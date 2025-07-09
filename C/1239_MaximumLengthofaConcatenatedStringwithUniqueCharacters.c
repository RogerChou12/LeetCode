int maxLength(char** arr, int arrSize) {
    int *mask=calloc(arrSize, sizeof(int));
    for(int i=0;i<arrSize;i++){
        char *str=arr[i];
        int len=strlen(str);
        for(int j=0;j<len;j++){
            int bit=1<<(str[j]-'a');
            if(mask[i] & bit){ // Duplicate character in the same string
                mask[i]=0;
                break;
            }
            mask[i] |= bit;
        }
    }
    
    int *sub=calloc((1<<arrSize), sizeof(int));
    int ans=0, subSize=1;
    for(int i=0;i<arrSize;i++){
        for(int j=subSize-1;j>=0;j--){
            if(sub[j] & mask[i]){ // Overlap
                continue;
            }
            int sub_str=sub[j] | mask[i];
            sub[subSize++]=sub_str;
            
            // Count length of string
            int length=0;
            while(sub_str){
                length += (sub_str & 1);
                sub_str >>= 1;
            }
            ans = fmax(ans, length);
        }
    }
    return ans;
}