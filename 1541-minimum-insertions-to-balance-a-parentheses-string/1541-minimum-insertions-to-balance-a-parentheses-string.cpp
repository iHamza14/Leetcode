class Solution {
public:
    int minInsertions(string s) 
    {
        int n = (int)s.size();
        int cnt =0;
        int ans =0;
        for(int i =0; i<n ; i++)
        {
            if(s[i]=='(') cnt++;
            else 
            {
                if(i < n-1 && s[i+1] == ')') 
                {
                    i++;
                } 
                else 
                {
                    ans++;
                }
                if(cnt==0) 
                {
                    ans++;
                } 
                else 
                {
                    cnt--;
                }
            }
        }    
        ans+= abs(cnt)*2;
        return ans;
    }
};