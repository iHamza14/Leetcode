class Solution {
    using ll = long long;
public:

    ll check(ll mid , vector<int>& coins)
    {
        int n = coins.size();
        ll total =0;
        for(int mask = 1; mask < (1<<n); mask++)
        {
            ll l =1;
            ll taken = __builtin_popcountll(mask);
            for(int j =0; j<n; j++)
            {
                if(mask & (1<<j))
                {
                    l = lcm(l,1ll*coins[j]);
                }
            }

            if(taken&1)
            {
                total += (mid/l);
            }
            else
            {
                total -= (mid/l);
            }
        }
        return total;
    }

    long long findKthSmallest(vector<int>& coins, int k) 
    {
        ll low = *min_element(coins.begin(),coins.end());
        ll high = 1ll*k*low;
        ll ans = high;
        while(low<=high)
        {
            ll mid = low + (high-low)/2;
            if(check(mid,coins) >= k)
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
    }
};