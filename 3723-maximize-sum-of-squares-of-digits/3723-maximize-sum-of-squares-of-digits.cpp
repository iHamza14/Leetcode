class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > 9*num) return "";
        string ans = "";
        while(num>0)
        {
            if(sum>9)
            {
                ans.push_back('9');
                sum-=9;
            }
            else
            {
                ans.push_back(sum+'0');
                sum=0;
            }
            num--;
        }
        return ans;
    }
};