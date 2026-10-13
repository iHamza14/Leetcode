class Solution {
    using ll = long long;
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = (int)nums.size();
        vector<ll> a;
        for(int i =0; i<n; i++)
        {
            a.push_back(1ll*nums[i]*nums[i]);
        }
        sort(a.rbegin(),a.rend());
        ll ans =0;
        for(int i =0; i<n; i++)
        {
            if(i<=(n+1)/2 - 1) ans+=a[i];
            else ans-=a[i];
        }
        return ans;
    }
};