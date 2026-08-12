class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l =0;
        int n = nums.size();
        int ans =0;
        map<int,int> mpp;
        for(int r=0; r<n ; r++)
        {
            mpp[nums[r]]++;
            while(mpp[nums[r]] > k) mpp[nums[l++]]--;
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};