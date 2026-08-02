class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, vector<int>& piles){
        if(i>j){
            return 0;
        }
        if(i==j){
            return piles[i];
        }
        if(dp[i][j] != -1) return dp[i][j];

        int take_i = piles[i] + min(solve(i+2,j,piles),solve(i+1 , j-1 ,piles));
        int take_j = piles[j] + min(solve(i,j-2,piles),solve(i+1,j-1,piles));

        return dp[i][j] = max(take_i,take_j);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        dp.assign(n, vector<int>(n,-1));
        int total_sum = accumulate(piles.begin(),piles.end(),0);

        int alice_score = solve(0,n-1,piles);

        int bob_score = total_sum - alice_score ;

        return alice_score > bob_score ;
    }
};