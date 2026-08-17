class Solution {
    using ll = long long;
public:

    // int solve(int l , int r , vector<vector<int>> &dp, vector<int> &pref)
    // {
    //     if(l==r) return 0;

    //     if(dp[l][r] !=-1) return dp[l][r];

    //     int res = 0;

    //     for(int i =l ; i<r; i++)
    //     {
    //         int pref1 = pref[i+1] - pref[l];
    //         int pref2 = pref[r+1] - pref[i+1];

    //         if(pref1 == pref2)
    //         {
    //             res = max({res , pref1 + solve(l,i,dp,pref), pref2+solve(i+1,r,dp,pref)});
    //         }
    //         else if(pref1> pref2)
    //         {
    //             res = max({res, pref2 + solve(i+1,r,dp,pref)});
    //         }
    //         else
    //         {
    //             res = max({res, pref1 + solve(l,i,dp,pref)});
    //         }
    //     }
    //     return dp[l][r] = res;
    // }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> pref(n+1,0);
        for(int i =0; i<n; i++) pref[i+1] = pref[i] + stoneValue[i];

        vector<vector<int>> dp(n,vector<int> (n,0));

        for(int len = 2 ; len<=n; len++)
        {
            for(int l =0; l+len -1 < n; l++)
            {
                int r = l+len-1;
                for(int i =0; i<r ; i++)
                {
                    int pref1 = pref[i+1] - pref[l];
                    int pref2 = pref[r+1] - pref[i+1];

                    if(pref1 == pref2)
                    {
                        dp[l][r] = max({dp[l][r] , pref1 + dp[l][i], pref2+dp[i+1][r]});
                    }
                    else if(pref1> pref2)
                    {
                        dp[l][r] = max(dp[l][r], pref2 + dp[i+1][r]);
                    }
                    else
                    {
                        dp[l][r] = max(dp[l][r], pref1 + dp[l][i]);
                    }
                }
            }
        }

        return dp[0][n-1];
    }
};