int getSum(int a, int b) {
    // a^b -> sum without carry
    // a&b -> compute carry
    return b==0?a:getSum((a^b), (unsigned int)(a&b)<<1);
}