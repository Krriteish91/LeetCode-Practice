class Solution {
public:
    struct Node {
        int len;
        int pref;
        int suff;
        int best;
        char leftChar;
        char rightChar;
    };

    vector<Node> SegTree;

    Node merge(Node a, Node b) {
        Node res;

        res.len = a.len + b.len;
        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.pref = a.pref;
        res.suff = b.suff;
        res.best = max(a.best, b.best);

        if (a.rightChar == b.leftChar) {
            res.best = max(res.best, a.suff + b.pref);

            if (a.pref == a.len)
                res.pref = a.len + b.pref;

            if (b.suff == b.len)
                res.suff = b.len + a.suff;
        }

        return res;
    }

    void buildSegTree(int idx, int l, int r, string& s) {
        if (l == r) {
            SegTree[idx] = {1, 1, 1, 1, s[l], s[l]};
            return;
        }

        int mid = l + (r - l) / 2;

        buildSegTree(2 * idx + 1, l, mid, s);
        buildSegTree(2 * idx + 2, mid + 1, r, s);

        SegTree[idx] = merge(
            SegTree[2 * idx + 1],
            SegTree[2 * idx + 2]
        );
    }

    void UpdateSegTree(int pos, char val, int idx, int l, int r, string& s) {
        if (l == r) {
            s[pos] = val;
            SegTree[idx] = {1, 1, 1, 1, val, val};
            return;
        }

        int mid = l + (r - l) / 2;

        if (pos <= mid) {
            UpdateSegTree(pos, val, 2 * idx + 1, l, mid, s);
        } else {
            UpdateSegTree(pos, val, 2 * idx + 2, mid + 1, r, s);
        }

        SegTree[idx] = merge(
            SegTree[2 * idx + 1],
            SegTree[2 * idx + 2]
        );
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        int n = s.size();

        SegTree.resize(4 * n);

        buildSegTree(0, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            UpdateSegTree(
                queryIndices[i],
                queryCharacters[i],
                0,
                0,
                n - 1,
                s
            );

            ans.push_back(SegTree[0].best);
        }

        return ans;
    }
};