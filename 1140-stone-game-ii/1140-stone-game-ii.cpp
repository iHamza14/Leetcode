class Solution {
public:
    int n;
    int func(int idx , int m ,int turn, vector<int> &piles, vector<int> &prefSum , vector<vector<vector<int>>> &dp)
    {
            if(idx >= n) return 0;
		    //idx to idx+x

            if(dp[idx][m][turn] != -1) return dp[idx][m][turn];
		    if(turn) 
            {
	            int best = 0;
                for(int x =1 ; x<=2*m; x++)
                {
                    int curr ;
                    if(idx+x < n ) curr = prefSum[idx+x] - prefSum[idx];
                    else curr = prefSum[n] - prefSum[idx];
                    best = max(best , curr + func(idx+x , max(m,x) , !turn , piles,prefSum,dp));
                }
                return dp[idx][m][turn] = best;
            }
            else 
            {   
	            int best = INT_MAX;
                for(int x =1 ; x<=2*m; x++)
                {
                    // if(idx+x < n ) curr = prefSum[idx+x] - prefSum[idx];
                    // else curr = prefSum[n] - prefSum[idx];
                    best = min(best , func(idx+x , max(m,x) , !turn , piles,prefSum,dp));
                }
                return dp[idx][m][turn] = best;
            }
    }

    int stoneGameII(vector<int>& piles) 
    {
        n = piles.size();
	    vector<vector<vector<int>>> dp(n,vector<vector<int>> (n+1,vector<int> (2,-1)));
	    int turn = 1;
	    vector<int> prefSum(n+1,0);
        for(int i =1; i<=n ; i++)
        {
            prefSum[i]=prefSum[i-1]+piles[i-1];
        }
	    return func(0,1,turn,piles,prefSum,dp);
    }
};