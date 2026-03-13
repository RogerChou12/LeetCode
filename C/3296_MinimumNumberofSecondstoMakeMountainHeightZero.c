long long minNumberOfSeconds(int mountainHeight, int* workerTimes, int workerTimesSize) {
    int maxworkerTime=0;
    for(int i=0;i<workerTimesSize;i++){
        if(workerTimes[i]>maxworkerTime){
            maxworkerTime=workerTimes[i];
        }
    }
    long long left=1;
    long long right=(long long)maxworkerTime*mountainHeight*(mountainHeight+1)/2;
    long long ans=0;
    while(left<=right){
        long long mid=(left+right)/2;
        long long count=0;
        for(int i=0;i<workerTimesSize;i++){
            long long k=(long long)(-1+sqrt(1+8*mid/workerTimes[i]))/2;
            count+=k;
        }
        if(count>=mountainHeight){
            ans=mid;
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    return ans;
}