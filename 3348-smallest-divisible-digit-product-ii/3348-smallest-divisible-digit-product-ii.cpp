#define pb push_back
class Solution {
    using ll = long long;
public:

    bool checkpf(ll t)
    {
        vector<int> a = {2,3,5,7};
        for(int k =0; k<4; k++)
        {
            while(t % a[k] == 0)
            {
                t/=a[k];
            }
        }

        return t==1;
    }

    string fillspace(int space , ll req)
    {
        string s = "";
        for(int d = 9 ; d>=2; d--)
        {
            while(req % d == 0)
            {
                s.pb(d+'0');
                req/=d;
            }
        }

        while((int)s.size() < space)
        {
            s.pb('1');
        }
        reverse(s.begin(),s.end());
        return s;
    }

    string smallestNumber(string num, ll t) 
    {
        bool ok = true;
        ok = checkpf(t);
        if(!ok) return "-1";
        
        int n = (int)num.size();
        vector<ll> rem(n+1,t);
        for(int i=0; i<n; i++) 
        {
            int d = num[i]-'0';
            if(d == 0) break;
            rem[i+1] = rem[i]/gcd(rem[i],(ll)d);
        }
        if(rem[n] == 1) return num;

        int start = num.find('0');
        if(start == string::npos) start = n-1;
        for(int i =start; i>=0; i--) 
        {
            ll req = rem[i];
            int space = n-i;

            for(int d = (num[i]-'0')+1; d <= 9; d++) 
            {
                ll newreq = req / gcd(req,d);
                string r = fillspace(space-1,newreq);

                if((int)r.size() == space-1) 
                {
                    string ans = num.substr(0,i);
                    ans.push_back(d+'0');
                    ans += r;
                    return ans;
                }
            }
        }
        return fillspace(n+1,t); 
    }
};