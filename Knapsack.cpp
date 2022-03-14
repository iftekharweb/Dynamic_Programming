1. Time complexity O(n*m)  | Best approch


int knapsack(int n,int k , vector<int> weight,vector<int> cost)
{
        vector<vector<int> > dp(n+1, vector<int> (k+1, 0));
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=k; j++)
            {
                int X, Y;
                if(!i) X = 0;
                else X = dp[i-1][j];
                if(j - weight[i]<0 || !i) Y = 0;
                else Y = dp[i-1][j-weight[i]] + cost[i];
                dp[i][j] = max(X,Y);
            }
        }
        return dp[n][k];
}


Examples:
https://codeforces.com/problemset/problem/1633/D
