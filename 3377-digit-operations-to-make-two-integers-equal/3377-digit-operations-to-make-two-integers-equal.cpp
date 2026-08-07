class Solution {
public:

    vector<bool> sieve()
    {
        const int N = 10000;
        vector<bool> prime(N+1,true);
        prime[0]=false;
        prime[1]=false;
        for(int i = 2; i*i<=N; i++)
        {
            if(!prime[i]) continue;
            for(int j = i*i ; j<=N; j+=i)
            {
                prime[j]=false;
            }
        }
        return prime;
    }

    int minOperations(int n, int m)
    {
        vector<bool> prime = sieve();
        if(prime[n] || prime[m]) return -1;

        vector<long long> dist(10000,LLONG_MAX);
        priority_queue<pair<long long,int> , vector<pair<long long,int>> , greater<pair<long long,int>>> pq;
        pq.push({n,n});
        dist[n]=n;
        while(!pq.empty())
        {
            auto [cost,node] = pq.top();
            pq.pop();

            string t = to_string(node);

            for(int i =0; i<t.size(); i++)
            {
                if(t[i] > '0')
                {
                    string t1 = t;
                    t1[i]--;

                    if(i==0 && t1[i] == '0') continue;
                    int reach = stoi(t1);
                    if(!prime[reach] && dist[node] + reach < dist[reach])
                    {
                        dist[reach]  = dist[node] + reach;
                        pq.push({dist[reach],reach});
                    }
                    
                }
            }

            for(int i =0; i<t.size(); i++)
            {
                if(t[i] < '9')
                {
                    string t1 = t;
                    t1[i]++;

                    int reach = stoi(t1);
                    if(!prime[reach] && dist[node] + reach < dist[reach])
                    {
                        dist[reach]  = dist[node] + reach;
                        pq.push({dist[reach],reach});
                    }
                }
            }
        }
        return dist[m]==LLONG_MAX? -1:dist[m];
    }
};