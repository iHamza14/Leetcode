class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int cnt = count(nums.begin(),nums.end(),target);
        int st = 0;
        for(int i =0; i<nums.size(); i++)
        {
            if(nums[i] < target) st++;
        }

        vector<int> ans;
        while(cnt>0)
        {
            ans.push_back(st++);
            cnt--;
        }
        return ans;
    }
};