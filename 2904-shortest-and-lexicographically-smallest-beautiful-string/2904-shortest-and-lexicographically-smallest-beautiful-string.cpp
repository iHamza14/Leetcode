class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int len =INT_MAX;
        int start = -1;

        int one = 0;
        int l =0;
        for(int r =0; r<n; r++)
        {
            if(s[r] == '1') one++;
            while(one > k) 
            {
                if(s[l]=='1') one--; 
                l++;
            }
            while(l<=r && s[l] == '0') l++;

            if(one == k)
            {
                if(len > r-l+1)
                {
                    start = l;
                    len = r-l+1;
                }
                else if(len == r-l+1)
                {
                    if(s.substr(start,len) > s.substr(l,r-l+1))
                    {
                        start = l ;
                        len = r-l+1;
                    }
                }
            } 
        }

        return ((start == -1) ? "" : s.substr(start,len));
    }
};