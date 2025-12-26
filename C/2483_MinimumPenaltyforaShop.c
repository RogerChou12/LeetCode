int bestClosingTime(char* customers) {
    int hours=strlen(customers);
    int minPenalty=0, penalty=0, closed=0;
    
    for(int i=0;i<hours;i++){
        if(customers[i]=='Y'){
            penalty--;
        }
        else{
            penalty++;
        }
        if(penalty<minPenalty){
            minPenalty=penalty;
            closed=i+1;
        }
    }
    return closed;
}