class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;

        for(int i=0 ; i<grid.size() ; i++){
            for(int j=0 ; j<grid[0].size() ; j++){
                nums.push_back(grid[i][j]);
            }
        }
        sort(nums.begin(), nums.end());

        int target = nums[nums.size()/2] ;
        int op = 0;
        for(int i=0 ; i<nums.size() ; i++){
            int diff = abs(nums[i]-target);
            if(diff%x == 0)
            op += diff/x ;
            else return -1;
        }
        return op;
    }
};