class Solution {
public:
    typedef pair<int, int> P;

    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> s;
        for(int i = 0; i<k; i++) 
        {
            s.insert(i);
        }

        priority_queue<P,vector<P>,greater<P>> busy;
        vector<int> count(k,0);

        for(int i = 0; i<(int)arrival.size(); i++) 
        {
            int time = arrival[i];
            while(!busy.empty() && busy.top().first <= time) 
            {
                int server = busy.top().second;
                busy.pop();
                s.insert(server);
            }

            int target = i%k;
            auto it = s.lower_bound(target);

            if(it == s.end()) it = s.begin();
            if(s.empty()) continue;

            auto get = *it;
            s.erase(it);
            busy.push({time + load[i], get});
            count[get]++;

        }

        int maxi = *max_element(begin(count),end(count));
        vector<int> ans;
        for(int i = 0; i<k; i++) 
        {
            if(count[i] == maxi) ans.push_back(i);
        }
        return ans;
    }
};