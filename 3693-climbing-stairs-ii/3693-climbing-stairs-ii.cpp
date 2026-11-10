class Solution {
public:
    int climbStairs(int n, vector<int>& costs) 
    {
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=costs[0]+1;
        if(n==1) return dp[1];
        dp[2]= min(costs[1]+4 , costs[1]+dp[1]+1);
        for(int i =3; i<=n; i++)
        {
            dp[i] = min({costs[i-1]+dp[i-3]+9 , costs[i-1]+dp[i-2]+4 , costs[i-1]+dp[i-1]+1});
        }
        return dp[n];

    }
};