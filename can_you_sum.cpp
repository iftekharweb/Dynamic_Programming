1. Time complexity O(huge) | Brute force approch
   Is is possible to generate the sum using the numbers of the array (as many times as possible)?

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

=> input
3
2 7
3 2
4 7
3 4 5 7
1 7
2
=> output 
possible
possible
impossible
