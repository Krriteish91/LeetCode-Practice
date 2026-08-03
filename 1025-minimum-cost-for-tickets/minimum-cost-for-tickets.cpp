class Solution {
public:
    vector<int> dp;
    int solve(int idx , vector<int>& days, vector<int>& costs){
        int n = days.size();
        if(idx >= n){
            return 0;
        }
        if(dp[idx] != -1) return dp[idx];

        int res = INT_MAX;
        // take 1-day pass
        res = min(res,costs[0] + solve(idx+1 , days , costs));

        // take 7-day pass
        int j = upper_bound(days.begin(),days.end(),days[idx]+6) - days.begin();
        res = min(res ,  costs[1] + solve(j,days,costs) );

        // take 30-day pass
        int  k = upper_bound(days.begin(), days.end(), days[idx] + 29) - days.begin();
        res = min(res , costs[2] + solve(k,days,costs));

        return dp[idx] = res;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        dp.assign(n+2 , -1);

        int ans = solve(0,days,costs);

        return ans;
    }
};