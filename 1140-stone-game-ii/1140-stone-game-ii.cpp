class Solution {
public:
    int solve(int i, int m, vector<int> &pref, vector<int>& piles, vector<vector<int>>& dp)
    {
        int n = (int)piles.size();
        if(i>=n)
        {
            return 0;
        }

        if(dp[i][m] != -1) return dp[i][m];
        int best =0;
        for(int x = 1; x<=2*m; x++)
        {
            best = max(best , pref[n]-pref[i] - solve(i+x,max(m,x),pref,piles,dp));
        }

        return dp[i][m]=best;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        vector<int> pref(n+1,0);
        for(int i =0; i<n; i++)
        {
            pref[i+1] = pref[i] + piles[i];
        }
        return solve(0,1,pref,piles,dp);
    }
};