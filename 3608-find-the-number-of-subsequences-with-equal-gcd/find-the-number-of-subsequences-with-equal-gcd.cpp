class Solution {
public:
    int dp[201][201][201];
    long long MOD = 1e9+7;
    int solve(vector<int>& nums, int idx , int first, int second){

        if(idx == nums.size()){
            if(first==0 || second==0) return 0;
            else if( first == second) return 1;
            else return 0;
        }
        if(dp[idx][first][second] != -1) return dp[idx][first][second];
        int skip = solve(nums, idx+1 , first,second);
        int take1 = solve(nums, idx+1 , gcd(first,nums[idx]),second);
        int take2 = solve(nums , idx+1 , first, gcd(second, nums[idx]));

        return dp[idx][first][second] = (0LL+skip+take1+take2)%MOD;
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1 , sizeof(dp));
        return solve(nums , 0, 0,0);
    }
};