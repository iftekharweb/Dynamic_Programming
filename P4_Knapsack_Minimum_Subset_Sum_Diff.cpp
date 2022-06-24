Topic : 01 Knapscak Variation 04
Problem : Minimum diff of two subset portions ?
Link : https://youtu.be/fJbIuhs24zQ
input : 
3
1 2 7
output : 
4

input:
3
1 6 7
output : 
0


vector<ll> value(N);
bool dp[N][N];

void Subset_sum(ll n , ll sum) {
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
        return;
}
ll Min_subset_sum_diff(ll n) {
        ll sum = 0;
        for(int i=0; i<n; i++) {
            sum += value[i];
        }
        Subset_sum(n,sum);
        ll diff = INF;
        for(int i=sum/2; i>=0; i--) {
            if(dp[n][i]==true) {
                diff = sum - 2*i;
                return diff;
            }
        }
}
ll solve()
{
        ll n = vin();
        for(int i = 0; i<n; i++) value[i] = vin();
        ll res = Min_subset_sum_diff(n);
        return res;
}
