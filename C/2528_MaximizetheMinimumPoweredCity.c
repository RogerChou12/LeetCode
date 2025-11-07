#include<stdbool.h>
#include<limits.h>

bool check(long long *diff, int r, int k, long long mid, int size){
    long long *diff01=malloc(sizeof(long long)*(size+1));
    memcpy(diff01, diff, (size+1)*sizeof(long long));
    long long sum=0, remain=k;
    for(int i=0;i<size;i++){
        sum+=diff01[i];
        if(sum<mid){
            long long add=mid-sum;
            if(remain<add){
                free(diff01);
                return false;
            }
            remain-=add;
            int end=fmin(size, i+2*r+1);
            diff01[end]-=add;
            sum+=add;
        }
    }
    free(diff01);
    return true;
}

long long maxPower(int* stations, int stationsSize, int r, int k) {
    long long *diff=calloc((stationsSize+1), sizeof(long long));
    long long ans=0;
    for(int i=0;i<stationsSize;i++){
        int left=fmax(0, i-r);
        int right=fmin(stationsSize, i+r+1);
        diff[left]+=stations[i];
        diff[right]-=stations[i];
    }
    long long minStations=LLONG_MAX;
    long long totalSum=0;
    for(int i=0;i<stationsSize;i++){
        if(stations[i]<minStations){
            minStations=stations[i];
        }
        totalSum+=stations[i];
    }
    long long low=minStations;
    long long high=totalSum+k;
    while(low<=high){
        long long mid=low+(high-low)/2;
        if(check(diff, r, k, mid, stationsSize)){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    free(diff);
    return ans;
}