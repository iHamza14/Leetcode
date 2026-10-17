class Solution {
    // using ll = long long;
public:
    int minSwaps(vector<int>& nums) {
        vector<vector<int>> v;
        int n = nums.size();
        for(int i =0; i<n; i++)
        {
            int sum =0;
            auto temp = nums[i];
            while(temp>0)
            {
                sum+=(temp%10);
                temp/=10;
            }
            v.push_back({sum,nums[i],i});
        }
        sort(v.begin(),v.end());
        vector<int> freq(n);

        for (int i = 0; i < n; i++) {
            freq[v[i][2]] = i;
        }

        int ans = 0;
        vector<bool> vis(n,false);

        for(int i = 0; i<n; i++) 
        {
            if(vis[i]) continue;
            int curIdx = i, cnt = 0;
            while(!vis[curIdx]) 
            {
                vis[curIdx] = true;
                curIdx = freq[curIdx];
                cnt++;
            }
            if(cnt>1) 
            {
                ans += cnt-1;
            }
        }
        return ans;
    }
};