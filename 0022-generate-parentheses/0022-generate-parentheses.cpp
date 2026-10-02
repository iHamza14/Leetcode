class Solution {
public:

    void solve(int open , int close , string curr , vector<string> &ans)
    {
        if(open == 0 && close==0) ans.push_back(curr);

        if(close<open) return ;

        if(open) solve(open-1,close, curr+'(' , ans);
        if(close) solve(open , close-1 , curr+')' , ans);

    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;
        solve(n,n,"",ans);
        return ans;
    }
};