class Solution {
public:
    struct Node 
    {
        int pre = 0;
        int suf = 0;
        int maxLen = 0;
        char leftChar = 0;
        char rightChar = 0;
        int len = 0;
    };

    int size;
    vector<Node> segTree;

    Node merge(const Node& L, const Node& R) 
    {
        Node res;

        res.len = L.len + R.len;

        res.leftChar = L.leftChar;
        res.rightChar = R.rightChar;

        res.pre = L.pre;
        if(L.pre == L.len && L.rightChar == R.leftChar) 
        {
            res.pre = L.pre + R.pre;
        }

        res.suf = R.suf;
        if(R.suf == R.len && L.rightChar == R.leftChar) 
        {
            res.suf = R.suf + L.suf;
        }

        res.maxLen = max(L.maxLen, R.maxLen);

        if(L.rightChar == R.leftChar) 
        {
            res.maxLen = max(res.maxLen, L.suf + R.pre);
        }

        return res;
    }

    void update(int pos, char ch) 
    {
        pos += size;
        segTree[pos] = {1, 1, 1, ch, ch, 1};
        for(pos /= 2; pos >= 1; pos /= 2) 
        {
            segTree[pos] = merge(segTree[2 * pos], segTree[2 * pos + 1]);
        }
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) 
    {
        int n = s.size();
        size = 1;
        while(size < n) 
        {
            size *= 2;
        }

        segTree.assign(2 * size, Node());

        for(int i = 0; i < n; i++) 
        {
            segTree[size + i] = {1, 1, 1, s[i], s[i], 1};
        }

        for(int i = size - 1; i >= 1; i--) 
        {
            segTree[i] = merge(segTree[2 * i], segTree[2 * i + 1]);
        }

        vector<int> result(queryIndices.size());

        for(int i = 0; i < queryIndices.size(); i++) 
        {
            update(queryIndices[i], queryCharacters[i]);
            result[i] = segTree[1].maxLen;
        }

        return result;
    }
};