class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        unordered_set<int> s(nums.begin(),nums.end());
        int mini = *min_element(nums.begin(),nums.end());
        int maxi = *max_element(nums.begin(),nums.end());
        for(int i = mini ; i<=maxi; i++)
            {
                if(s.find(i)==s.end())
                    ans.push_back(i);
            }
        return ans;
    }
};