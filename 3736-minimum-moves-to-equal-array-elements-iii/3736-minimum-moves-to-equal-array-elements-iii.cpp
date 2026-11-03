class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int get = nums[n-1];
        int ans =0;
        for(auto i : nums) ans += abs(get-i);
        return ans;
    }
};