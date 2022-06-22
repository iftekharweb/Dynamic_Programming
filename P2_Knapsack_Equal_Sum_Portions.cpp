Topic : 01 Knapscak Variation 01
Problem : Is Possible to generate sum from subset ?
Link : https://youtu.be/fJbIuhs24zQ
inpout : 
5
2 10 3 3 2
output : 
YES

inpout : 
5 
1 100 5 5 10
output : 
NO

1. Iterative + Top-Down + Tabulation Approch  |


vector<ll> value(N);
bool dp[N][N];

ll Knapsack_Subset_Sum(ll sum ,ll n)
{
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=sum; j++) {
                if(i==0 && j==0) dp[i][j] = true;
                else if(i && !j) dp[i][j] = true;
                else if(!i && j) dp[i][j] = false;
                else if(value[i-1]<=j) {
                    dp[i][j] = (dp[i-1][j-value[i-1]] || dp[i-1][j]);
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
}

bool Equal_sum_portions(ll n) {
        ll sum = 0;
        for(int i=0; i<n; i++) sum += value[i];
        if(sum%2) return false;
        ll halfSum = sum >> 1;
        return Knapsack_Subset_Sum(halfSum,n);
}

bool solve()
{
        ll n = vin();
        for(int i=0; i<n; i++) value[i] = vin();
        return Equal_sum_portions(n);
}
