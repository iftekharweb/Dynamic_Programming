1. Time COmplexity : O(n) | Memoization Apprroch (Top-Bottom)

vector<ll> dp(N,MOD);
ll MinSquare(ll n) {
        if(dp[n] != MOD) return dp[n];
        if(n==0 || n==1 || n==2 || n==3) return n;
        for(int i=1; i*i<=n; i++) {
            dp[n]  = min(MinSquare(n-i*i)+1, dp[n]);
        }
        return dp[n];
}


2. Time Complexity : O(n)  |  Iterative Approch (Bottom-Top)

vector<ll> dp(N,MOD);
ll MinSquare(ll n) {
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for(int i=0; i*i<=n; i++) {
            for(int j=0; i*i+j<=n; j++) {
                dp[i*i+j] = min(dp[i*i+j], 1+dp[j]);
            }
        }
        return dp[n];
}
