class DSU
{
private:
    vector<int> parent , size;
public:
    DSU(int n)
    {
        parent.resize(n);
        size.assign(n,1);
        iota(parent.begin(),parent.end(),0);
    }

    int find(int x)
    {
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x , int y)
    {
        int rootx = find(x);
        int rooty = find(y);

        if(rootx == rooty) return;

        if(size[rootx] < size[rooty]) swap(rootx,rooty);

        parent[rooty] = rootx;
        size[rootx] += size[rooty];
    }
};

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        DSU dsu(n);
        vector<pair<int,int>> v;
        for(int i =0; i<n; i++)
        {
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        for(int i =0; i<n-1; i++)
        {
            int x = v[i].first;
            int y = v[i+1].first;

            if(abs(x-y) <= limit) dsu.unite(v[i].second,v[i+1].second);
        }

        map<int,vector<int>> mpp;
        for(int i =0; i<n; i++)
        {
            int root = dsu.find(i);
            mpp[root].push_back(i);
        }

        vector<int> ans(n);

        for(auto [r,v] : mpp)
        {
            vector<int> temp;
            for(auto i : v)
            {
                temp.push_back(nums[i]);
            }

            sort(temp.begin(),temp.end());

            int c =0;
            for(auto i : v)
            {
                ans[i] = temp[c++];
            }
        }
        return ans;
    }
};