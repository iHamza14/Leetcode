// class Solution {
// public:
//     int solve(int i, vector<vector<int>> &books, int &shelfWidth, vector<int> &dp)
//     {
//         int n = books.size();
//         if(i>=n) return 0;

//         if(dp[i] != -1) return dp[i];

//         int res = INT_MAX;
//         int currW = 0;
//         int currH =0;
//         for(int j = i ; j<n; j++)
//         {
//             int t = books[j][0];
//             int h = books[j][1];
//             currW += t;
//             currH = max(currH , h);
//             if(currW>shelfWidth) break;
//             res = min(res, currH + solve(j+1,books,shelfWidth,dp));
//         }
//         return dp[i] = res;
//     }

//     int minHeightShelves(vector<vector<int>>& books, int shelfWidth) 
//     {
//         int n = books.size();
//         vector<int> dp(n,-1);
//         return solve(0,books,shelfWidth,dp);
//     }
// };

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) 
    {
        int n = books.size();
        vector<int> dp(n+1,INT_MAX);
        dp[n]=0;
        for(int i = n-1; i>=0; i--)
        {
            int currH = 0;
            int currW = 0;

            for(int j = i; j<n; j++)
            {
                currW += books[j][0];
                currH = max(currH,books[j][1]);

                if(currW > shelfWidth) break;

                dp[i]= min(dp[i] , currH + dp[j+1]);
            }
        }
        return dp[0];
    }
};