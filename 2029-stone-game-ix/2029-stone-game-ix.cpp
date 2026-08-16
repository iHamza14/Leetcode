class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> c(3,0);
        for(auto i : stones) c[i%3]++;

        if(c[0]%2 == 0) return c[1] > 0 && c[2] > 0;
        else return abs(c[1] - c[2]) > 2;
    }
};