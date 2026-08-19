class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) 
    {
        unordered_map<int,unordered_set<int>> mpp;
        for(auto i : reservedSeats)
        {
            int r = i[0];
            int s = i[1];
            mpp[r].insert(s);
        }
        int ans =0;
        for(auto &[r,v] : mpp)
        {
            int s1=1 , s2 =1 , s3 =1;
            if(v.count(2) || v.count(3)) s1 = 0;
            if(v.count(4) || v.count(5)) {s1 = 0; s2=0;}
            if(v.count(6) || v.count(7)) {s2 = 0; s3=0;}
            if(v.count(8) || v.count(9)) s3 = 0;

            if(s1==1)
            {
                s2=0;
                ans++;
            }
            if(s2==1)
            {
                s3 =0;
                ans++;
            }
            if(s3==1) ans++;
        }
        ans += (n-(int)mpp.size()) * 2;
        return ans;
    }
};