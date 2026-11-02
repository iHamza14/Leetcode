class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int n = nums.size();
        int median = nums[n/2];
        int ans =0;
        for(auto &i : nums) ans+= abs(median-i);
        return ans;
    }
};