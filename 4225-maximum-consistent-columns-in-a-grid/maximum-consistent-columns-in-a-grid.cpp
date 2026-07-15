class Solution {
public:
    vector<vector<int>> dp;
    bool canPick(int lCol, int cCol , vector<vector<int>>& grid, int limit){
        if(lCol == -1) return true;

        for(int i=0 ; i<grid.size() ; i++){
            if(abs(grid[i][lCol] - grid[i][cCol]) > limit) return false;
        }

        return true;
    }
    int solve(int lastCol, int currCol,vector<vector<int>>& grid, int limit){
        if(currCol == grid[0].size()) return 0;

        if( dp[lastCol + 1][currCol+1] != -1 ) return dp[lastCol+1][currCol+1];

        int skip = solve(lastCol , currCol+1 , grid,limit);
        int pick = 0;
        if(canPick(lastCol , currCol, grid, limit)){
            pick = solve(currCol, currCol+1,grid, limit) + 1;
        }

        return dp[lastCol+1][currCol+1] = max(skip, pick);
    }
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int m = grid.size();
        int n = grid[0].size();

        dp.assign(n+2, vector<int>(n+2,-1));

        return solve(-1,0,grid,limit);
    }
};