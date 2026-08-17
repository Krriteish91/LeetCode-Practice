class Solution {
public:
    vector<vector<int>> dp;
    int solve(int l, int r ,vector<int>& stoneValue,vector<int>& prefixSum){
        if(l==r){
            return 0;
        }
        if(dp[l][r] != -1) return dp[l][r];
        int leftRow , rightRow;

        int alice = -1;

        for(int k = l ; k<=r ; k++){
            leftRow = prefixSum[k] - prefixSum[l] + stoneValue[l];
            rightRow = prefixSum[r] - prefixSum[k];

            int score = 0;

            if(leftRow < rightRow){
                score = leftRow + solve(l,k,stoneValue,prefixSum);
            }
            else if(leftRow > rightRow){
                score = rightRow + solve(k+1 , r, stoneValue,prefixSum);
            }
            else{
                score = leftRow + max(solve(l,k, stoneValue,prefixSum) , solve(k+1,r,stoneValue,prefixSum));
            }
            alice = max(alice , score);
        }
        return dp[l][r] = alice;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.assign(n+1 , vector<int>(n+1 , -1));

        vector<int> prefixSum(n,0);
        prefixSum[0] = stoneValue[0];

        for(int i=1 ; i<n ; i++ ){
            prefixSum[i] = prefixSum[i-1]+stoneValue[i];
        }

        return solve(0,n-1 , stoneValue , prefixSum);
    }
};