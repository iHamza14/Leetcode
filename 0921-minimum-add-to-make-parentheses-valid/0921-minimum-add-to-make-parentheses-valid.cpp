class Solution {
public:
    int minAddToMakeValid(string s) {
        int open =0;
        int ans =0;
        for(auto i : s)
        {
            if(i=='(')
            {
                open++;
            }
            else
            {
                if(open) {open--; continue;}
                else ans++;
            }
        }

        if(open) ans+=abs(open);
        return ans;
    }
};