class Solution {
public:
    int solve(int i , vector<int> &stone, vector<int>& dp)
    {
        if(i>=(int)stone.size()) return 0;
        if(dp[i] != INT_MIN) return dp[i];

        int res = INT_MIN;
        if(i+2 < (int)stone.size()) res = max(res, stone[i] + stone[i+1] + stone[i+2] - solve(i+3,stone,dp));
        if(i+1 < (int)stone.size()) res = max(res, stone[i] + stone[i+1] - solve(i+2,stone,dp));
        if(i < (int)stone.size()) res = max(res, stone[i] - solve(i+1,stone,dp));

        return dp[i] = res;
        
    }
    string stoneGameIII(vector<int>& stone) {
        int n = stone.size();
        vector<int> dp(n,INT_MIN);
        int get = solve(0,stone,dp);
        // cout<<get<<endl;
        if(get == 0) return "Tie";
        else if(get>0) return "Alice";
        else return "Bob";
    }
};