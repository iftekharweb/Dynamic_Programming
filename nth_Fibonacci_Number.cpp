1. Time Complexity: O(2n) = O(n)  | Scape Complexity : O(2n) = O(n)  | Best approch

ll fib(ll n, vector<ll> &ff)
{
        if(ff[n]) return ff[n];
        if(n<=2) return 1;
        ff[n] = fib(n-1, ff) + fib(n-2, ff);
        return ff[n];
}
