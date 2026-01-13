double separateSquares(int** squares, int squaresSize, int* squaresColSize) {
    double yMax=0.0, total=0.0;
    for(int i=0;i<squaresSize;i++){
        int y=squares[i][1];
        int l=squares[i][2];
        total+=(double)l*l;
        if(y+l>yMax){
            yMax=y+l;
        }
    }
    double lo=0.0, hi=yMax;
    while(fabs(hi-lo)>1e-5){
        double mid=(hi+lo)/2.0;
        double area=0.0;
        for(int i=0;i<squaresSize;i++){
            int y=squares[i][1];
            int l=squares[i][2];
            if(y<mid){
                area+=l*fmin(l, mid-y);
            }
        }
        if(area<(total/2.0)){
            lo=mid;
        }
        else{
            hi=mid;
        }
    }
    return hi;
}