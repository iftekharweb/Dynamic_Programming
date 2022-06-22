Topic : 01 Knapscak Variation 03
Problem : how many to generate sum from subset ?
Link : https://youtu.be/fJbIuhs24zQ
inpout : 
5 10
2 3 7 8 10
output : 
3


1. Iterative + Top-Down + Tabulation Approch  |


vector<ll> value(N);
int dp[N][N];

ll Knapsack_Subset_Sum(ll sum ,ll n)
{
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=sum; j++) {
                if(i==0 && j==0) dp[i][j] = 1;
                else if(i && !j) dp[i][j] = 1;
                else if(!i && j) dp[i][j] = 0;
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
        ll n = vin() , k = vin();
        for(int i=0; i<n; i++) value[i] = vin();
        return Knapsack_Subset_Sum(k, n);
}
