Topic : 01 Knapscak Variation 05
Problem : Number of ways to partition (2 portions) the array with given diff ?
Link : https://youtu.be/fJbIuhs24zQ
input : 
3 12
1 6 7
output : 
1


1. Iterative + Top-Down + Tabulation Approch  |


/*
        S1 - S2 = diff
        S1 + S2 = arrSum
    _____________________________
    =>  2*S1 = diff + arrSum
    =>  S1 = (diff + arrSum) / 2;
*/

vector<ll> value(N);
ll dp[N][N];

ll Given_diff_Subset(ll n , ll sum) {
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=sum; j++) {
                if(i==0 && j==0) dp[i][j] = true;
                else if(i && !j) dp[i][j] = true;
                else if(!i && j) dp[i][j] = false;
                else if(value[i-1]<=j) {
                    dp[i][j] = (dp[i-1][j-value[i-1]] + dp[i-1][j]);
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
}
ll solve()
{
        ll n = vin() , diff = vin();
        ll sum = 0;
        for(int i = 0; i<n; i++) value[i] = vin();
        for(int i=0; i<n; i++) sum += value[i];
        if((sum+diff)%2) {
            return 0;
        }
        sum = (sum+diff)/2;
        ll res = Given_diff_Subset(n,sum);
        return res;
}
