class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string get = "";
        for(int i =0; i<n; i++)
            get+="#";
        vector<string> ans(m,get);

        for(int i =0; i<m ; i++)
        {
            for(int j =0; j<n ; j++)
            {
                if(i==0 || j==n-1)
                    ans[i][j]='.';
            }
        }
        return ans;
    }
};