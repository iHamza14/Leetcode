class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();
        unordered_map<string,string> mpp;
        for(auto i : knowledge)
        {
            mpp[i[0]]=i[1];
        }

        string ans = "";
        int i ;
        for(i =0; i<n;)
        {
            if(s[i] != '(')
            {
                ans.push_back(s[i]);
                i++;
                continue;
            }
            else
            {
                i++;
                string curr = "";
                while(s[i]!=')')
                {
                    curr.push_back(s[i++]);
                }
                if(mpp.find(curr) != mpp.end())
                {
                    ans+= mpp[curr];
                }
                else ans.push_back('?');
                i++;
            }
        }
        return ans;
    }
};