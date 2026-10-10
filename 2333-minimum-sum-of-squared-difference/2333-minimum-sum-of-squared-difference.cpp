class Solution {
    using ll = long long;
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<ll> a;
        for(int i =0; i<n ; i++)
        {
            a.push_back(abs(nums1[i]-nums2[i]));
        }
        
        sort(a.rbegin(),a.rend());

        map<ll,ll> mpp;
        for(auto i : a)
        {
            mpp[i]++;
            cout<<i<<" ";
        }
        cout<<endl;
        ll k = k1+k2;
        while(k>0)
        {
            auto it = mpp.end();
            it--;
            if((*it).first==0) {mpp.erase(it); break;}
            if((*it).second > k)
            {
                int rem = k;
                mpp[(*it).first]=(*it).second-k;
                mpp[(*it).first-1]+=rem;
                k=0;

            }
            else
            {
                mpp[(*it).first-1] += (*it).second;
                k-=(*it).second;
                mpp.erase(it);
            }
        }

        ll ans =0;
        for(auto i : mpp)
        {
            ans += i.second*i.first*i.first;
        }
        return ans;
    }
};