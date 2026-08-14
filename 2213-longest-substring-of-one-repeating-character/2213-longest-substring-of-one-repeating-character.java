class Node
{
        int len ;
        int pre ;
        int suf ;
        int maxLen ;
        char leftChar ;
        char rightChar ;

        Node() {}

        Node(int len , int pre, int suf, int maxLen, char leftChar, char rightChar) 
        {
            this.len = len;
            this.pre = pre;
            this.suf = suf;
            this.maxLen = maxLen;
            this.leftChar = leftChar;
            this.rightChar = rightChar;
        }
}

class Segtree
{
    int n;
    Node[] tree;
    int sz;

    Segtree(String s)
    {
        n = s.length();
        sz = 1;
        while(sz < n) sz*=2;
        tree = new Node[2*sz];

        for(int i = 0 ; i<n ; i++)
        {
            char ch = s.charAt(i);
            tree[sz+i] = new Node(1,1,1,1,ch,ch);
        }

        for(int i = n; i<sz; i++) 
        {
            tree[sz+i] = new Node(0, 0, 0, 0, '\0', '\0');
        }

        for(int i = sz-1 ; i>=1; i--)
        {
            tree[i] = merge(tree[2*i], tree[2*i + 1]);
        }
    }

    Node merge(Node L , Node R)
    {
        if(L.len == 0) return R;
        if(R.len == 0) return L;

        Node res = new Node(L.len + R.len , 0 , 0 , 0 , L.leftChar , R.rightChar);

        res.pre = L.pre;
        if(res.pre == L.len && L.rightChar == R.leftChar) res.pre += R.pre;

        res.suf = R.suf;
        if(res.suf == R.len && L.rightChar == R.leftChar) res.suf += L.suf;

        res.maxLen = Math.max(L.maxLen , R.maxLen);
        if(L.rightChar == R.leftChar)
        {
            res.maxLen = Math.max(res.maxLen, L.suf + R.pre);
        }

        return res;
    }

    void pointUpdate(int pos , char ch)
    {
        pos += sz;
        tree[pos] = new Node(1,1,1,1,ch,ch);

        pos/=2;
        while(pos>=1)
        {
            tree[pos] = merge(tree[pos*2] , tree[pos*2 + 1]);
            pos/=2;
        }
    }
}

class Solution {
    public int[] longestRepeating(String s, String queryCharacters, int[] queryIndices) 
    {
        Segtree st = new Segtree(s);
        int[] ans = new int[queryCharacters.length()];

        for(int i =0; i<queryCharacters.length(); i++)
        {
            st.pointUpdate(queryIndices[i],queryCharacters.charAt(i));
            ans[i] = st.tree[1].maxLen;
        }
        return ans;
    }
}