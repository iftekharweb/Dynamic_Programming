Q. How many ways to reach nth stair using 1,2,or,3 steps?

1. Time Complexity : O(n) | Iterative Approch

vector<ll> dp(1000001);
void stairCase()
{
        dp[1] = 1;                      // [1]
        dp[2] = 2;                      // [1,1], [2]
        dp[3] = 4;                      // [3], [1,1,1], [2,1], [1,2]
        for(int i=4; i<1000001; i++){
            dp[i] = (dp[i-1]+dp[i-2]+dp[i-3])%MOD;
        }
        return;
}

2. Time Complexity : O(n) | Recursive Approch

vector<ll> dp(1000001,0);
ll stairCase(ll n)
{
        if(dp[n]) return dp[n];
        if(n<=2) {
            dp[n] = n;
            return dp[n];
        }
        if(n==3) {
            dp[n] = 4;
            return dp[n];
        }
        dp[n] = (stairCase(n-1)+stairCase(n-2)+stairCase(n-3))%MOD;
        return dp[n];
}

Example:
https://www.codechef.com/problems/JAM11
