class Solution {
public:
    bool isValid(string s) {
        vector<int> v;
        for(auto i : s)
        {
            if(i==')' || i==']' || i=='}')
            {
                if((int)v.size() == 0) return false;
                else 
                {
                    if(v.back() == '(' && i==')') {v.pop_back();}
                    else if(v.back() == '[' && i==']') {v.pop_back();}
                    else if(v.back() == '{' && i=='}') {v.pop_back();}
                    else return false;
                }
            }
            else 
            {
                v.push_back(i);
            }
        }
        return !(int)v.size();
    }
};