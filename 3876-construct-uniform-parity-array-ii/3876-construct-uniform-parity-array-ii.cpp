class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int mini = *min_element(nums.begin(), nums.end());

        if(mini&1)
            return true;

        for(auto i : nums) 
        {
            if(i&1) return false;
        }

        return true;
    }
};