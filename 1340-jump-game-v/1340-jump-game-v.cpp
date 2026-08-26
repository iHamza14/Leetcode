class Solution {
public:
    int n ;
    int solve(int i , vector<int>&arr , int d, vector<int> &dp)
    {
        if(dp[i]!=-1) return dp[i];

        int curr =1;
        for(int j = i-1; j>=max(i-d,0); j--)
        {
            if(arr[j] >= arr[i]) break;
            curr = max(curr , 1 + solve(j,arr,d,dp));
        }
        for(int j = i+1; j<=min(i+d,n-1); j++)
        {
            if(arr[j] >= arr[i]) break;
            curr = max(curr , 1 + solve(j,arr,d,dp));
        }

        return dp[i] = curr;
    }
    int maxJumps(vector<int>& arr, int d) 
    {
        n = arr.size();
        vector<int> dp(n+1,-1);
        int res = 1;
        for(int i =0; i<n; i++)
        {
            res = max(res ,solve(i,arr,d,dp));
        }
        return res;
    }
};