class Solution {
    using ll = long long;
public:

    int check(ll mid , ll a, ll b , ll c)
    {
        ll l1 = lcm(a,b);
        ll l2 = lcm(b,c);
        ll l3 = lcm(c,a);
        ll l4 = lcm(l1,c);

        ll res = mid/a + mid/b + mid/c - mid/l1 - mid/l2 - mid/l3 + mid/l4;
        return res;
    }

    int nthUglyNumber(int n, int a, int b, int c) 
    {
        int low = 1;
        int high = 2*(int)1e9;
        int ans = -1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(check(mid,a,b,c)>=n)
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