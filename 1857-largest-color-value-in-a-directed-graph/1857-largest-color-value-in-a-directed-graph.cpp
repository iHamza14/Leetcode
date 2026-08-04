class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> graph(n);
        vector<int> in(n,0);

        for(auto i : edges)
        {
            int u = i[0];
            int v = i[1];

            graph[u].push_back(v);
            in[v]++;
        }

        vector<vector<int>> dp(n,vector<int>(26,0));
        queue<int> q;
        for(int i =0; i<n; i++)
        {
            if(in[i]==0) q.push(i);
        }

        int ans = INT_MIN;
        while(!q.empty())
        {
            auto u = q.front();
            q.pop();

            dp[u][colors[u]-'a']++;
            for(int c =0; c<26 ; c++)
            {
                ans = max(ans,dp[u][c]);
            }

            for(auto v : graph[u])
            {
                for(int c =0; c<26; c++)
                {
                    dp[v][c] = max(dp[v][c],dp[u][c]);
                }
                in[v]--;
                if(in[v]==0) q.push(v);
            }
        }

        for(auto i : in) if(i!=0) return -1;
        return ans;
    }
};