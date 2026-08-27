class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        multiset<char> ms;
        for(auto i : s) ms.insert(i);

        vector<string> ans;
        string prev = "";
        for(auto i : target)
        {
            auto it = ms.upper_bound(i);
            if(it != ms.end())
            {
                auto get = *it;
                auto temp = prev;
                temp.push_back(get);
                ms.erase(it);
                for(auto j : ms) temp.push_back(j);
                ans.push_back(temp);
                ms.insert(get);
            }
            auto same = ms.find(i);
            if(same == ms.end()) break;
            prev.push_back(*same);
            ms.erase(same);
        }
        if(ans.empty()) return "";
        return *min_element(ans.begin(),ans.end());
    }
};