class Solution {
public:
    using ll = long long;
    int smallestUniqueSubarray(vector<int>& nums) 
    {
        int n = nums.size();
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

        const ll MOD1 = 1e9 + 7;
        const ll MOD2 = 1e9 + 9;

        ll k1 = uniform_int_distribution<ll>(256, 1e6)(rng);
        ll k2 = uniform_int_distribution<ll>(256, 1e6)(rng);

        while(k1 == k2) k2 = uniform_int_distribution<ll>(256, 1e6)(rng);


        auto binexp = [&](int a , int b , ll mod){
            ll ans =1;
            while(b){
                if(b&1){
                    ans = (ans*a)%mod;
                }

                a = (1ll*a*a)%mod;
                b>>=1;
            }
            return ans;
        };

        vector<ll> pref1(n+1),pref2(n+1);
        vector<ll> pw1(n+1),pw2(n+1);
        vector<ll> invpw1(n+1),invpw2(n+1);

        pw1[0]=pw2[0]=1;
        for(int i =1; i<=n; i++){
            pw1[i]=(pw1[i-1]*k1)%MOD1;
            pw2[i]=(pw2[i-1]*k2)%MOD2;
        }

        ll invk1 = binexp(k1,MOD1-2,MOD1);
        ll invk2 = binexp(k2,MOD2-2,MOD2);

        invpw1[0]=invpw2[0]=1;
        for(int i=1;i<=n;i++)
        {
            invpw1[i]=invpw1[i-1]*invk1%MOD1;
            invpw2[i]=invpw2[i-1]*invk2%MOD2;
        }

        for(int i=0;i<n;i++){
            pref1[i+1] =(pref1[i]+(nums[i]+1)*pw1[i])%MOD1;
            pref2[i+1] =(pref2[i]+(nums[i]+1)*pw2[i])%MOD2;
        }

        auto gethash=[&](int l , int r){
            ll hash1 = (pref1[r+1]-pref1[l]+MOD1)%MOD1;;
            ll hash2 = (pref2[r+1]-pref2[l]+MOD2)%MOD2;

            hash1 = hash1 * invpw1[l]%MOD1;
            hash2 = hash2 * invpw2[l]%MOD2;
            return make_pair(hash1,hash2);
        };

        auto check=[&](int len){
            map<pair<int,int>,int> freq;
            for(int i =0; i+len-1<n; i++){
                freq[gethash(i,i+len-1)]++;
            }

            for(auto &i : freq){
                if(i.second==1) return true;
            }
            return false;

        };

        int low =1;
        int high = n;

        int ans = high;

        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(check(mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};