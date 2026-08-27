class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        map<char,int> mpp;
        for(auto i : s) mpp[i]++;

        string ans = "";
        for(auto i : target)
        {
            if(mpp[i]>0)
            {
                ans.push_back(i);
                mpp[i]--;
            }
            else
            {
                auto it = mpp.upper_bound(i);
                auto c = (*it).first;
                if(it == mpp.end()) 
                {
                    return "";
                }
                else
                {
                    ans.push_back(c);
                    mpp[c]--;
                    break;
                }
            }
        }
        for(auto i : mpp)
        {
            while(mpp[i.first]>0)
            {
                ans.push_back(i.first);
                mpp[i.first]--;
            }
        }

        if(ans==target) return "";
        return ans;
    }
};