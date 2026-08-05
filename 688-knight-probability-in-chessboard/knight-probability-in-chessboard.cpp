class Solution {
public:
    vector<int> dRow = {-2,-2,-1,1,2,2,1,-1};
    vector<int> dCol = {-1,1,2,2,1,-1,-2,-2};
    vector<vector<vector<double>>> dp;
    
    double solve(int i, int j,int moves ,int n, int k){
        if(i<0 || j <0 || i>=n || j >= n){
            return 0.0;
        }
        if(moves == k){
            return 1.0;
        }

        if(dp[i][j][moves] != -1) return dp[i][j][moves];

        double res = 0.0;
        for(int m=0 ; m<8 ; m++){
            int nr = i + dRow[m];
            int nc = j + dCol[m];

            res += solve(nr,nc,moves+1,n,k);
        }
        return dp[i][j][moves] = res/8.0 ;
    }
    double knightProbability(int n, int k, int row, int column) {
        dp.assign(n,vector<vector<double>>(n,vector<double>(k+1,-1)));
        return solve(row,column,0,n,k);
    }
};