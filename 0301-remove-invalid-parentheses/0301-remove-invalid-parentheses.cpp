class Solution {
public:

    void solve(int i, string &curr ,int cnt , int &maxlen, string &s , set<string> &st)
    {
        if(cnt < 0) return;
        if(i==(int)s.size())
        {
            if(cnt ==0)
            {
                if(curr.length() > maxlen)
                {
                    st.clear();
                    st.insert(curr);
                    maxlen = curr.length();
                }
                else if(curr.length() == maxlen)
                {
                    st.insert(curr);
                }
            }
            return;
        }
        if(s[i]!='(' && s[i]!=')') 
        {
            curr.push_back(s[i]);
            solve(i+1,curr,cnt , maxlen,s,st);
            curr.pop_back();
            return;
        }

        curr.push_back(s[i]);
        if(s[i]=='(') solve(i+1,curr,cnt+1 , maxlen,s,st);
        else solve(i+1,curr,cnt-1 , maxlen,s,st);
        curr.pop_back();

        solve(i+1,curr,cnt , maxlen,s,st);

    }

    vector<string> removeInvalidParentheses(string s) 
    {
        set<string> st;
        int maxlen = 0;
        string curr = "";
        solve(0,curr,0,maxlen,s,st);
        vector<string> ans;
        for(auto &i : st) ans.push_back(i); 
        return ans;
    }
};