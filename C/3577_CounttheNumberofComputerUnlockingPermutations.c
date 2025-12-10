#define MOD 1000000007

int countPermutations(int* complexity, int complexitySize) {
    long long ans=1;
    for(int i=1;i<complexitySize;i++){
        if(complexity[i]<=complexity[0]){
            return 0;
        }
    }
    for(int n=2;n<complexitySize;n++){
        ans=ans*n%MOD;
    }
    return ans;
}