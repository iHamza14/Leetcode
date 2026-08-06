class Solution {
public:
    int smallestNumber(int n, int t) 
    {
        for(int i = n ; ; i++)
        {
            int temp = i;
            long long prod = 1;
            while(temp)
            {
                int dig = temp%10;
                temp/=10;
                prod*=dig;
            }
            if(prod%t==0) return i;
        }
    }
};