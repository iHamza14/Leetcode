class Solution {
    using ll = long long;
public:
    ll x ;
    int n ;
    vector<ll> calc;
    ll solve(int i , int k , vector<int> &nums , vector<vector<ll>> &dp)
    {
        if(k<=0) return 0;
        if(i>=n || n-i < x*k) return LLONG_MAX/4;

        if(dp[i][k] != -1) return dp[i][k];

        ll skip = solve(i+1,k,nums,dp);
        ll take = calc[i] + solve(i+x,k-1,nums,dp);

        return dp[i][k] = min(skip,take);
    }
    ll minOperations(vector<int>& nums, int x, int k) 
    {
        n = nums.size();
        this->x = x;
        vector<vector<ll>> dp(n+1,vector<ll>(k+1,-1));
        calc.resize(n);
        multiset<int> left,right;
        ll lsum =0, rsum =0;
        int l =0;
        for(int r =0; r<n; r++)
        {
            if(left.empty() || nums[r] <= *left.rbegin()) 
            {
                left.insert(nums[r]);
                lsum += nums[r];
            }
            else 
            {
                right.insert(nums[r]);
                rsum += nums[r];
            }

            if(r-l+1 > x) 
            {
                int val = nums[l];

                if (left.find(val) != left.end()) 
                {
                    left.erase(left.find(val));
                    lsum -= val;
                }
                else 
                {
                    right.erase(right.find(val));
                    rsum -= val;
                }
                l++;
            }

            if(r-l+1 == x)
            {
                int target = (x+1) / 2;

                while((int)left.size() > target) 
                {
                    int val = *left.rbegin();
                    left.erase(left.find(val));
                    lsum -= val;

                    right.insert(val);
                    rsum += val;
                }

                while((int)left.size() < target) 
                {
                    int val = *right.begin();
                    right.erase(right.find(val));
                    rsum -= val;

                    left.insert(val);
                    lsum += val;
                }
                ll median = *left.rbegin();
                calc[l] = median*(left.size()) - lsum + rsum - median*(right.size());
            }
        }
        return solve(0,k,nums,dp);
    }
};