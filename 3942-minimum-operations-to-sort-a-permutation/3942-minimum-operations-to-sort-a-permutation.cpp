class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        int n = nums.size();
        int ans =-1;
        int drop = 0;
        for(int i =0; i<n-1 ; i++)
            {
                if(nums[i]>nums[i+1]) drop++;
            }
        if(nums[n-1]>nums[0]) drop++;
        if(drop<=1)
        {
            int idx = -1;
            for(int i =0; i<n; i++)
                {
                    if(nums[i]==0) idx=i;
                }
            ans=min(idx,2+n-idx);
        }
        // reverse(nums.begin(),nums.end());
        drop = 0;
        for(int i =0; i<n-1 ; i++)
            {
                if(nums[i]<nums[i+1]) drop++;
            }
        if(nums[n-1]<nums[0]) drop++;
        if(drop<=1)
        {
            int idx = -1;
            for(int i =0; i<n; i++)
                {
                    if(nums[i]==0) idx=i;
                }
            if(ans==-1) ans=min({n-idx-1+1,1+(idx+1)%n});
            else ans= min({ans,n-idx-1+1,1+(idx+1)%n});
        }
        return ans;
    }
};