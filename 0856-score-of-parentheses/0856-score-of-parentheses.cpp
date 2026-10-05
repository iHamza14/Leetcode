class Solution {
public:
    int scoreOfParentheses(string s) {
        int cnt =0;
        int ans =0;
        for(int i =0; i<(int)s.size(); i++)
        {
            if(s[i]=='(')
            {
                cnt++;
            }
            else
            {
                cnt--;
                if(i>0 && s[i-1] == '(') ans+= (1<<cnt);
            }
        }
        return ans;
    }
};