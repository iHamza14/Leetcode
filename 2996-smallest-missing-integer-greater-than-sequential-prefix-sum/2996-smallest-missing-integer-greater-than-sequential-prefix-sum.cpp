class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        for(int i =1; i<n; i++)
        {
            if(nums[i-1] + 1 == nums[i])
            {
                sum+=nums[i];
            }
            else
            {
                break;
            }
        }
        set<int> s(nums.begin(),nums.end());
        for(int i = sum ; ; i++)
        {
            if(!s.count(i)) return i;
        }
    }
};