class Solution {
public:
    int minMoves(vector<int>& nums) {
        // 1 1 2 3 
        int mini = *min_element(nums.begin(),nums.end());
        int ans =0;
        for(auto &i : nums)
        {
            ans+= (i-mini);
        }
        return ans;
    }
};