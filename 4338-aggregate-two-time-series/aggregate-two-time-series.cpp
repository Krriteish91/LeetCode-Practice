class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<vector<int>> ans;
        int n = series1.size();
        int m = series2.size();

        int i=0 , j=0;

        while(i<n || j<m){
            if(i<n && j<m && series1[i][0] == series2[j][0]){
                ans.push_back({series1[i][0] , series1[i][1] + series2[j][1]});
                i++;
                j++;
            }
            else if(i<n && j<m && series1[i][0] < series2[j][0]){
                ans.push_back({series1[i][0] , series1[i][1] + series2[j][1]});
                i++;
            }
            else if(i<n && j<m && series1[i][0] > series2[j][0]){
                ans.push_back({series2[j][0] , series1[i][1]+series2[j][1]});
                j++;
            }
            else if(i==n && j<m){
                ans.push_back(series2[j]);
                j++;
            }
            else{
                ans.push_back(series1[i]);
                i++;
            }
        }
        return ans;
    }
};