class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = (int)s.size();
        int ans =0;
        unordered_map<int,int> mpp;
        int l =0;
        for(int r =0; r<n; r++)
        {
            mpp[s[r]]++;
            while(mpp[s[r]]>2) mpp[s[l++]]--;

            ans = max(ans,r-l+1);
        }
        return ans;
    }
};