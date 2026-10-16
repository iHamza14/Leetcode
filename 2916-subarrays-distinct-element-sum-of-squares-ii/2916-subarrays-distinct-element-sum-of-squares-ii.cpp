//will do it on 18 oct 

class Solution {
    static constexpr long long MOD = 1'000'000'007LL;

    struct SegmentTree {
        int n;
        vector<long long> tree, lazy;

        explicit SegmentTree(int size) : n(size), tree(4 * size), lazy(4 * size) {}

        void push(int node, int lo, int hi) {
            if (lazy[node] == 0 || lo == hi) return;
            int mid = lo + (hi - lo) / 2;
            long long pending = lazy[node];
            int left = 2 * node, right = left + 1;
            tree[left] += pending * (mid - lo + 1);
            tree[right] += pending * (hi - mid);
            lazy[left] += pending;
            lazy[right] += pending;
            lazy[node] = 0;
        }

        long long query(int node, int lo, int hi, int ql, int qr) {
            if (qr < lo || hi < ql) return 0;
            if (ql <= lo && hi <= qr) return tree[node];
            push(node, lo, hi);
            int mid = lo + (hi - lo) / 2;
            return query(2 * node, lo, mid, ql, qr)
                 + query(2 * node + 1, mid + 1, hi, ql, qr);
        }

        void add(int node, int lo, int hi, int ql, int qr) {
            if (qr < lo || hi < ql) return;
            if (ql <= lo && hi <= qr) {
                tree[node] += hi - lo + 1;
                lazy[node]++;
                return;
            }
            push(node, lo, hi);
            int mid = lo + (hi - lo) / 2;
            add(2 * node, lo, mid, ql, qr);
            add(2 * node + 1, mid + 1, hi, ql, qr);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }

        long long rangeSum(int l, int r) { return query(1, 0, n - 1, l, r); }
        void rangeAdd(int l, int r) { add(1, 0, n - 1, l, r); }
    };

public:
    int sumCounts(vector<int>& nums) {
        SegmentTree st((int)nums.size());
        unordered_map<int, int> lastSeen;
        long long currentSquareSum = 0, answer = 0;

        for (int r = 0; r < (int)nums.size(); ++r) {
            int p = lastSeen.count(nums[r]) ? lastSeen[nums[r]] : -1;
            long long oldSum = st.rangeSum(p + 1, r);
            long long delta = 2 * oldSum + (r - p);
            currentSquareSum += delta;
            answer = (answer + currentSquareSum) % MOD;
            st.rangeAdd(p + 1, r);
            lastSeen[nums[r]] = r;
        }
        return (int)answer;
    }
};