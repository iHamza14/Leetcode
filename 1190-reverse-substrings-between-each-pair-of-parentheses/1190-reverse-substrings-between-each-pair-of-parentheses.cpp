class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string curr = "";

        for(auto i : s) 
        {
            if(i == '(') 
            {
                st.push(curr);
                curr = "";
            }
            else if(i == ')') 
            {
                reverse(curr.begin(), curr.end());
                curr = st.top() + curr;
                st.pop();
            }
            else 
            {
                curr += i;
            }
        }
        return curr;
    }
};