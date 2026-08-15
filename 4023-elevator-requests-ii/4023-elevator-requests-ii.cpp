class Solution {
    using ll = long long;
public:
    long long elevatorRequests(int n, int start, vector<int>& requests) 
    {
        int m = requests.size();
        sort(requests.begin(),requests.end());
        ll dp[1500][1500][2];
        for(int l =0; l<m; l++)
        {
            for(int r = 0; r<m; r++)
            {
                dp[l][r][0] = dp[l][r][1] = LLONG_MAX;
            }
        }

        for(int l = 0; l<m; l++)
        {
            dp[l][l][0] = dp[l][l][1] = 1ll * abs(start-requests[l]) * m;
        }

        for(int len = 1 ; len <= m; len++)
        {
            for(int l = 0; l<m; l++)
            {
                int r = l + len -1;
                if(r>=m) continue;

                int left = m - (r-l+1);
                if(l>0) 
                dp[l-1][r][0] = min(
                    dp[l][r][0] + 1ll* abs(requests[l] - requests[l-1]) * left ,
                    dp[l][r][1] + 1ll* abs(requests[r] - requests[l-1]) * left
                );

                if(r<m-1) 
                dp[l][r+1][1] = min(
                    dp[l][r][0] + 1ll* abs(requests[l] - requests[r+1]) * left ,
                    dp[l][r][1] + 1ll* abs(requests[r] - requests[r+1]) * left
                );
            }
        }
        return min(dp[0][m-1][0] , dp[0][m-1][1]);
    }
};