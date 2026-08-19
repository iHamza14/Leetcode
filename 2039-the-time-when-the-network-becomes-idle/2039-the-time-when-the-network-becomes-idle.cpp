class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        int time = 1;

        vector<vector<int>> adj(n + 1);

        for (auto i : edges) {
            int u = i[0];
            int v = i[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q;
        q.push(0);

        vector<int> dist(n, -1);
        int cnt = 0;
        dist[0] = 0;

        while (!q.empty()) {
            int sz = q.size();
            cnt++;

            for (int k = 0; k < sz; k++) {
                auto top = q.front();
                q.pop();

                for (auto a : adj[top]) {
                    if (dist[a] == -1) {
                        dist[a] = cnt;
                        q.push(a);
                    }
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            cout << dist[i] << " ";

            ans = max(
                patience[i] < 2 * dist[i]
                    ? (2 * dist[i] - 1) / patience[i] * patience[i] + 2 * dist[i]
                    : 2 * dist[i],
                ans
            );

            cout << ans << endl;
        }

        return ans + 1;
    }
};