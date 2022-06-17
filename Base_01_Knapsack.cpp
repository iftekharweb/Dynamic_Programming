Memoization Approch : 01 Knapscak
Problem : Maximum profit
Link : https://youtu.be/fJbIuhs24zQ
inpout : 
5 4
1 2 3 4 5
4 2 3 5 1
output : 
7

  
  
vector<ll> weight(N) , value(N);
ll dp[N][N];
ll w , n;

ll Knapsack(ll tw ,ll tn) {
        if(tn == 0 || tw == 0) return 0;
        if(dp[tn][tw]!=-1) {
            return dp[tn][tw];
        }
        if(weight[tn-1]<=tw) {
            /* 
                choice_1 : include the item
                choice_2 : don't include
            */
            ll choice_1 = value[tn-1] + Knapsack(tw-weight[tn-1],tn-1);
            ll choice_2 = Knapsack(tw,tn-1);
            return dp[tn][tw] = max(choice_1,choice_2);
        }
        else if(weight[tn-1]>tw){
            return dp[tn][tw] = Knapsack(tw,tn-1);
        }
}

ll solve()
{
        n = vin() , w = vin();
        for(int i=0; i<=n; i++) for(int j=0; j<=w; j++) dp[i][j] = -1;
        for(int i=0; i<n; i++) weight[i] = vin();
        for(int i=0; i<n; i++) value[i] = vin();
        ll mx = Knapsack(w,n)
        return mx;
}
int main() 
{
        FastIO;
        cout << solve() << endl;
        return 0;
}
