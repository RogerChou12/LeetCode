uint32_t reverseBits(uint32_t n) {
    uint32_t ans=0;
    for(int i=0;i<32;i++){
        uint32_t current_bit = 1&(n>>i);
        ans |= (current_bit<<(31-i));
    }
    return ans;
}