class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxn = *max_element(nums.begin(),nums.end());

        vector<long long> freq(maxn+1,0);
        for(int i=0 ; i<nums.size() ; i++){
            freq[nums[i]]++;
        }
        vector<long long> exact(maxn+1,0);
        for(int g=maxn ; g>=1 ; g--){
            long long cnt = 0;

            for(int multiple = g; multiple <= maxn ; multiple+=g){
                cnt += freq[multiple];
            }

            long long total_pairs = (cnt-1)*cnt/2;

            exact[g] = total_pairs;

            for(int mp = 2*g ; mp<=maxn ; mp+=g){
                exact[g] -= exact[mp];
            }}
            vector<long long> prefix(maxn + 1, 0);
            for (int g = 1; g <= maxn; g++)
                prefix[g] = prefix[g - 1] + exact[g];

            vector<int> ans;
            for(long long q: queries){
                int g = upper_bound(prefix.begin(),prefix.end(),q) - prefix.begin();
                ans.push_back(g);
            }
            return ans;
    }
};