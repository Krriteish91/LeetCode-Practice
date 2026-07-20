class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j <n ; j++){
                if((j+k) < n){
                    ans[i][j+k] = grid[i][j];
                }
                else{
                    int ni = ((j+k)/n + i)%m ;
                    int nj = (j+k)%n ;
                    ans[ni][nj] = grid[i][j];
                }
            }
        }
        return ans;
    }
};