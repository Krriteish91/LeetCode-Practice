class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, vector<vector<int>>& dungeon){
        int m = dungeon.size();
        int n = dungeon[0].size();

        if(i>=m || j>=n) return 1e9;

        if(i==m-1 && j==n-1){
            if(dungeon[i][j] <= 0){
                return 1-dungeon[i][j];
            }
            else{
                return 1;
            }
        }
        if(dp[i][j] != -1) return dp[i][j];
        
        int res = min(solve(i+1,j,dungeon),solve(i,j+1,dungeon)) - dungeon[i][j];
        
        return dp[i][j] = res <= 0 ? 1 : res;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        dp.assign(m, vector<int>(n,-1));

        return solve(0,0,dungeon);
    }
};