class Solution {
public:
    int largestInteger(vector<int>& nums, int k) 
    {
        int n = nums.size();
        if(k==1 )
        {
            unordered_map<int,int> mpp;
            for(auto i : nums) mpp[i]++;
            int maxi = INT_MIN;
            for(auto i : mpp)
            {
                if(i.second == 1)
                {
                    maxi = max(maxi,i.first);
                }
            }
            return maxi==INT_MIN? -1:maxi;
        }
        else if(k==n)
        {
            return *max_element(nums.begin(),nums.end());
        }
        else
        {
            int start = nums[0];
            int end = nums[n-1];
            int check1 = 1;
            int check2 = 1;
            for(int i = 1; i<n-1; i++)
            {
                if(start==nums[i]) check1=0;
                if(end==nums[i]) check2=0;
            }
            if(start == end) return -1;
            if(check1 && check2) return max(start,end);
            else if(!check1 && !check2) return -1;
            else if(!check1) return end;
            else return start;
        }
    }
};