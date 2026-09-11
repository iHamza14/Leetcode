class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> ans;
        int n = digits.size();

        for(int i = 0; i < n; i++) 
        {
            for(int j = i + 1; j < n; j++) 
            {
                for(int k = j + 1; k < n; k++) 
                {
                    vector<int> p = {digits[i], digits[j], digits[k]};
                    sort(p.begin(),p.end());
                    do {
                        if(p[0] == 0) continue;
                        if(p[2] % 2 != 0) continue;

                        int num = p[0]*100 + p[1]*10 + p[2];
                        ans.insert(num);
                    } while(next_permutation(p.begin(),p.end()));
                }
            }
        }

        return ans.size();
    }
};