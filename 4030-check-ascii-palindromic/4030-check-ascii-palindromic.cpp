class Solution {
public:
    bool isPalindromic(string s) {
        string binary = "";

        for (char c : s) 
        {
            int x = (int)c;

            for (int bit = 7; bit >= 0; bit--) 
            {
                binary += ((x >> bit) & 1) + '0';
            }
        }

        int l = 0, r = binary.size() - 1;

        while (l < r) 
        {
            if (binary[l] != binary[r]) return false;
            l++;
            r--;
        }

        return true;
    }
};