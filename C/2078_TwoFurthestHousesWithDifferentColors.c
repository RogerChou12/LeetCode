int maxDistance(int* colors, int colorsSize) {
    int ans=0;
    for(int i=0;i<colorsSize;i++){
        if(colors[0]!=colors[colorsSize-1-i] || colors[colorsSize-1]!=colors[i]){
            ans=fmax(ans, colorsSize-1-i);
        }
    }
    return ans;
}