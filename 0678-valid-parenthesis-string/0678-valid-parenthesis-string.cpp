class Solution {
public:
    bool checkValidString(string s) 
    {
        int n = (int)s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        dp[0][0]=1;
        for(int i =0; i<n ; i++)
        {
            for(int open =0; open<=n; open++)
            {
                if(!dp[i][open]) continue;
                if(s[i]=='(')
                {
                    dp[i+1][open+1]=1;
                }
                else if(s[i]==')')
                {
                    if(open>0) dp[i+1][open-1]=1;
                }
                else
                {
                    dp[i+1][open+1]=1;
                    dp[i+1][open]=1;
                    if(open>0) dp[i+1][open-1]=1;
                }
            }
        }
        return dp[n][0];
    }
};