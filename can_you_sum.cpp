Q. Is is possible to generate the sum using the numbers of the array (as many times as possible)?
=> input
3
2 7
3 2
4 7
3 4 5 7
2 300
7 14
=> output 
possible
possible
impossible

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

1. Time complexity O(n*m) | Space complexity O(m) | Best approch
   
ll canSum(ll targetSum, set<ll> a, vector<ll> &mm)
{
        if(mm[targetSum] != -1) return mm[targetSum];
        if(targetSum == 0) return 1;
        if(targetSum < 0) return 0;

        for(auto x:a){
            ll remainder = targetSum - x;
            if(canSum(remainder,a,mm) == 1){
                mm[targetSum] = 1;
                return mm[targetSum];
            }
        }
        mm[targetSum] = 0;
        return mm[targetSum];
}
string solve()
{
        ll n = vin();
        ll m = vin();
        set<ll> a;
        vector<ll> mm(1001,-1);
        for(int i=0; i<n; i++) {
            ll x = vin();
            a.insert(x);
        }
        ll res = canSum(m,a,mm);
        if(!res) return "impossible";
        return "possible";
}

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

2. Time complexity O(n^m) | Space complexity O(m) | Brute force approch

bool canSum(ll targetSum, vector<ll> a)
{
        if(targetSum == 0) return true;
        if(targetSum < 0) return false;
        for(auto x:a) {
            ll remainder = targetSum - x; 
            if(canSum(remainder,a) == true) {
                return true;
            }
        }
        return false;
}
string solve()
{
        ll n = vin();
        ll m = vin();
        vector<ll> a(n);
        for(int i=0; i<n; i++) {
                cin >> a[i];
        }
        bool res = canSum(m,a);
        if(!res) return "impossible";
        return "possible";
}


