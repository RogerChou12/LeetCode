int minFlips(int a, int b, int c){
    int flip = 0;
    while(a||b||c){
        if(c&1){
            if(((a|b)&1)==0){
                flip++; // One of a,b must flip to 1
            }
        }
        else{
            flip += (a&1);
            flip += (b&1);
        }

        a >>= 1;
        b >>= 1;
        c >>= 1;
    }
    return flip;
}