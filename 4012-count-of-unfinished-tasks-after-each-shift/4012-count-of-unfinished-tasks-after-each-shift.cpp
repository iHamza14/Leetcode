class Solution {
    using ll = long long;
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();
        vector<ll> pref(n+1,0);

        for(int i =0; i<n; i++)
        {
            pref[i+1] = pref[i]+tasks[i];
        }

        vector<int> ans;
        int m = shifts.size();
        int idx = 0; // i am at which task 
        int done = 0; // i did how much of that task
        for(auto s : shifts)
        {
            ll remaining = pref[n] - pref[idx] - done;

            if(s >= remaining)
            {
                ans.push_back(0);
                done =0;
                idx=0;
                continue;
            }

            if(s < tasks[idx] - done)
            {
                ans.push_back(n-idx);
                done += s;
                continue;
            }
            
            s-= tasks[idx]-done;
            
            ll target = pref[idx+1] + s;
            auto it = upper_bound(pref.begin(),pref.end(),target) - pref.begin() - 1;

            if(it == n)
            {
                idx =0;
                done =0;
                ans.push_back(0);
            }
            else
            {
                idx = it;
                done = target - pref[idx];
                ans.push_back(n-idx);
            }
        }
        // n = 3
        // 2 3 4
        // 0 2 5 9 
        // 0 1 2 3
        return ans;
    }
};