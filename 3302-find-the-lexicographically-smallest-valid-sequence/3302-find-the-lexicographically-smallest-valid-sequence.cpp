class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        vector<int> seq;
        int n = word1.size();
        int m = word2.size();
        bool took=0;
        int j=m-1;
        vector<int> longest_suff(n+1);
        for(int i=n-1;i>=0;i--)
        {
            if(j>=0 and word1[i]==word2[j])
            {
                j--;
            }
            longest_suff[i] = m-j-1;
        }

        j=0;
        for(int i=0;i<n;i++)
        {
            if(j>=m)break;
            if(word1[i]==word2[j])
            {
                seq.push_back(i);
                j++;
            }
            else{
                if(!took)
                {
                    int left = m-j-1;
                    if(longest_suff[i+1]>=left)
                    {
                        took=1;
                        seq.push_back(i);
                        j++;
                    }
                }
            }
        }
        if(seq.size()==m) return seq;
        return {};
    }
};