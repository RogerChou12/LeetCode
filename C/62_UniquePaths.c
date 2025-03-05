int uniquePaths(int m, int n) {
    // choose (m-1) right moves and (n-1) down moves from a total of m+n-2 moves to reach end
    // C(m+n-2)(m-1)=C(m+n-2)(n-1)
    long ans = 1;
    for(int i=m+n-2, j=1;i>fmax(m-1, n-1);i--, j++){
        ans = ans*i/j;
    }
    return ans;
}