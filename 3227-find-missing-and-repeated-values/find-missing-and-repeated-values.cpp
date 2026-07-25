class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int duplicate;
        int sum = 0;
        unordered_map<int,int> mpp;

        for(int i=0; i<row ; i++){
            for(int j=0 ; j<col ; j++){
                if(mpp.find(grid[i][j]) != mpp.end()){
                    duplicate = grid[i][j];
                }
                sum += grid[i][j];
                mpp[grid[i][j]]++;
            }
        }
        int n = row*row;
        int actual_sum =  n*(n+1)/2 ;
        int missing;

        sum = sum - duplicate;
        missing = actual_sum - sum;
        return {duplicate,missing};
    }
};