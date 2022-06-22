Topic : 01 Knapscak Variation 01
Problem : Is Possible to generate sum from subset ?
Link : https://youtu.be/fJbIuhs24zQ
inpout : 
5 11
2 3 7 8 10
output : 
YES

inpout : 
5 11
2 3 7 5 10
output : 
NO

1. Iterative + Top-Down + Tabulation Approch  |

vector<ll> value(N);
bool dp[N][N];

ll Knapsack(ll sum ,ll n)
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

string solve()
{
        ll n = vin() , sum = vin();
        for(int i=0; i<n; i++) value[i] = vin();
        bool ok = Knapsack(sum,n);
        if(ok) return "YES";
        return "NO";
}
