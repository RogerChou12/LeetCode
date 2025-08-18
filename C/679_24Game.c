#include<stdbool.h>
#include<math.h>

bool dfs(double *arr, int arrSize){
    if(arrSize==1) return fabs(arr[0]-24.0)<1e-6;

    for(int i=0;i<arrSize;i++){
        for(int j=0;j<arrSize;j++){
            if(i==j) continue;
            double next_arr[4];
            int idx=0;
            for(int k=0;k<arrSize;k++){
                if(k!=i && k!=j) next_arr[idx++]=arr[k]; // Numbers exclude 'a' and 'b'
            }
            double a=arr[i], b=arr[j], candidates[6];
            int cnt=0;
            candidates[cnt++]=a+b;
            candidates[cnt++]=a-b;
            candidates[cnt++]=b-a;
            candidates[cnt++]=a*b;
            if(fabs(b)>1e-6) candidates[cnt++]=a/b;
            if(fabs(a)>1e-6) candidates[cnt++]=b/a;
            // Put result of 'a' op 'b' into 'next_arr'
            for(int c=0;c<cnt;c++){
                next_arr[idx]=candidates[c];
                if(dfs(next_arr, idx+1)) return true;
            }
        }
    }
    return false;
}

bool judgePoint24(int* cards, int cardsSize) {
    double nums[4];
    for(int i=0;i<cardsSize;i++){
        nums[i]=(double)cards[i];
    }

    return dfs(nums, cardsSize);
}