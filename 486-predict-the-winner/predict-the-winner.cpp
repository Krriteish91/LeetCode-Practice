class Solution {
public:
    bool solve(int i, int j, int player1 , int player2 , int turn,vector<int>& nums){

        if(i==j){
            if(turn%2 == 1){
                if(player1 + nums[i] >= player2 ) return true;
                return false;
            }
            else{
                if(player1 >= player2+nums[i]) return true;
                return false;
            }
        }

        if(turn%2 ==1){
            return solve(i+1 , j ,player1 + nums[i] , player2 , turn+1 , nums) || solve(i , j-1 ,player1 +nums[j] , player2 , turn+1 , nums);
        }
    
        return solve(i+1 , j ,player1 , player2 + nums[i] , turn+1 , nums) && solve(i,j-1 , player1,player2+nums[j] , turn+1 ,nums);
    
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return solve(0, n-1 , 0,0,1,nums);
    }
};