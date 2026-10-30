class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> graph(n);
        for(auto i : edges)
        {
            int u = i[0];
            int v= i[1];
            int c = i[2];
            graph[u] .push_back({v,c});
        }
        vector<vector<int>> dist(n,vector<int> (k+1,1e9));
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq;
        pq.push({0,0,1});
        dist[0][1] =0;

        while(!pq.empty())
        {
            auto get = pq.top();
            pq.pop();

            int node = get[1];
            int cost = get[0];
            int total = get[2];
            if(cost > dist[node][total]) continue;
            for(auto [v,w] : graph[node])
            {
                int newtotal = (labels[node]==labels[v])? total +1 : 1;
                if(newtotal > k) continue;
                if(w + cost < dist[v][newtotal])
                {
                    dist[v][newtotal] = w+cost;
                    pq.push({dist[v][newtotal],v,newtotal});
                }
            }
        }

        int ans =INT_MAX;
        for(int i =1; i<=k; i++)
        {
            ans= min(ans,dist[n-1][i]);
        }
        return ans==1e9? -1: ans;
    }
};