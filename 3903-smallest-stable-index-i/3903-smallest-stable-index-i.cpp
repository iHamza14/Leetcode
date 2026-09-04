class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = (int)nums.size();
        vector<int> maxi(n+1,INT_MIN);
        for(int i =0; i<(int)nums.size(); i++)
        {
            maxi[i+1] = max(nums[i],maxi[i]);
        }

        int mini = INT_MAX;
        int sm = INT_MAX;
        int idx = -1;
        for(int j = (int)nums.size()-1; j>=0; j--)
        {
            mini = min(mini , nums[j]);

            if(maxi[j+1] - mini <=k)
            {
                idx = j;
                sm = maxi[j+1]-mini;
            }
        }
        return idx;
        
    }
};