class Solution {
public:
    vector<string> columnStates;
    vector<vector<int>> dp;
    int mod = 1e9+7 ; 

    void generateColumnStates(int i, string curr , char prev , int m){
        if(i==m){
            columnStates.push_back(curr);
            return;
        }

        for(char c : {'R' , 'G' , 'B'}){
            if(c == prev) continue;

            generateColumnStates(i+1, curr+c , c , m);
        }
    }

    int solve(int remCol , int prevStat , int m){

        if(remCol == 0){
            return 1;
        }
        if(dp[remCol][prevStat] != -1) return dp[remCol][prevStat] ;
        int total_ways = 0;

        string prevCol = columnStates[prevStat];

        for(int nextState = 0 ; nextState < columnStates.size() ; nextState++ ){
            string nextCol = columnStates[nextState];

            bool valid = true;

            for(int i=0 ; i<nextCol.size() ; i++){
                if(prevCol[i] == nextCol[i]){
                    valid = false;
                    break;
                }
            }
            if(valid){
                total_ways = (total_ways + solve(remCol-1 , nextState , m))%mod ;
            }
        }
        return dp[remCol][prevStat]=total_ways;
    }

    int colorTheGrid(int m, int n) {
        
        generateColumnStates(0,"",'#',m);

        int num_states = columnStates.size();

        dp.assign(n+1 , vector<int>(num_states+1 , -1));

        int result = 0;

        for(int i=0 ; i<num_states ; i++){
            result = (result + solve(n-1,i , m))%mod ;
        }

        return result;
    }
};