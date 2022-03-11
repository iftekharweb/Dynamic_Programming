1. Time Complexity : O(2*(n+m)) = O(n+m) | Space Complexity : O(2*(n+m)) = O(n+m) | Best Approch
   Q. Number of ways to travel from the top corner to the bottom corner

ll gridTraveler(ll row,ll col, map<pair<ll,ll>,ll> &mm)
{
        ll n = min(row,col);
        ll m = max(row,col);
        if(mm[{n,m}]) return mm[{n,m}];
        if(n==1 && m==1) return 1;
        if(n==0 || m==0) return 0;
        mm[{n,m}] = gridTraveler(n-1,m, mm) + gridTraveler(n,m-1, mm);
        return mm[{n,m}];
}

ll solve()
{
        ll n = vin();
        ll m = vin();
        map<pair<ll,ll>,ll> mm;
        ll x = gridTraveler(n,m, mm);
        return x;
}
