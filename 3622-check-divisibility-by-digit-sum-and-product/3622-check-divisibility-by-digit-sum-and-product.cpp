class Solution {
public:
    bool checkDivisibility(int n) {
        int s=0,p=1;
        int temp = n;
        while(temp)
        {
            int d = temp%10;
            s+=d;
            p*=d;
            temp/=10;
        }
        if(n % (s+p)) return false;
        else return true;
    }
};