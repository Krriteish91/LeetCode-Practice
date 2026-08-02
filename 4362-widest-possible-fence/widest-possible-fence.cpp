class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<int,int> cnt;
        for (int p : planks) cnt[p]++;

        vector<int> vals;
        vals.reserve(cnt.size());
        for (auto& [v, c] : cnt) vals.push_back(v);
        sort(vals.begin(), vals.end());

        int m = vals.size();
        unordered_map<long long,int> sumPairs;

        for (int i = 0; i < m; i++) {
            long long v1 = vals[i];
            int c1 = cnt[vals[i]];
            for (int j = i; j < m; j++) {
                long long v2 = vals[j];
                int c2 = cnt[vals[j]];
                long long target = v1 + v2;
                int pairs = (i == j) ? (c1 / 2) : min(c1, c2);
                if (pairs > 0) sumPairs[target] += pairs;
            }
        }

        int ans = 0;
        // baseline: using planks of a single height as-is
        for (auto& [v, c] : cnt) ans = max(ans, c);

        // combine singles + pairs for every achievable sum
        for (auto& [target, pairs] : sumPairs) {
            int single = cnt.count((int)target) ? cnt[(int)target] : 0;
            ans = max(ans, single + pairs);
        }

        return ans;
    }
};