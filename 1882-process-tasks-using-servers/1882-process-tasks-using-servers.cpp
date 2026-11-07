class Solution {
    using ll = long long;
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        vector<int> ans(m);
        set<pair<int,int>> fs;
        for(int i =0; i<n; i++)
        {
            fs.insert({servers[i],i});
        }
        ll t =0;
        //ending time , server index
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        for(int i =0; i<tasks.size(); i++)
        {
            t= max(t,(ll)i);
            while(!pq.empty() && t >= pq.top().first) 
            {
                auto idx = pq.top().second;
                auto w = servers[idx];
                fs.insert({w,idx});
                pq.pop();
            }
            //free
            if(!fs.empty())
            {
                auto get = *fs.begin();
                fs.erase(fs.begin());

                pq.push({t+tasks[i], get.second});
                ans[i]= get.second;
            }
            else
            {
                t=pq.top().first;
                while(!pq.empty() && t >= pq.top().first) 
                {
                    auto idx = pq.top().second;
                    auto w = servers[idx];
                    fs.insert({w,idx});
                    pq.pop();
                }

                auto get = *fs.begin();
                fs.erase(fs.begin());

                pq.push({t+tasks[i], get.second});
                ans[i]= get.second;
            }
        }
        return ans;
    }
};