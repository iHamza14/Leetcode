#define ll long long
class Solution {
public:
    ll countCommas(long long n) 
    {
        ll ans =0;
        ll t =1;
        for(ll i =1000; i<=n; i*=1000)
            {
                ans += (n-i+1);
            }
        return ans;
    }
};