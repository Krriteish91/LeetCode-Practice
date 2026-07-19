class Solution {
public:
    vector<vector<int>> mergeIntervals(vector<vector<int>>& meetings){
        vector<vector<int>> intervals;
        int n = meetings.size();
        sort(meetings.begin(), meetings.end());
        int i=0 ;
        while(i<n){
            int end = meetings[i][1];
            int j=i+1;
            while(j<n && meetings[j][0] <= end){
                if(end < meetings[j][1] ) end = meetings[j][1];
                j++;
            }
            intervals.push_back({meetings[i][0],end});
            i = j;     
        }
        return intervals;

    }
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<vector<int>> intervals;
        intervals = mergeIntervals(meetings);
        if(intervals.size() == 1){
            return days - (intervals[0][1] - intervals[0][0] + 1);
        }
        int Occ_days = 0;
        for(int i=0 ; i<intervals.size() ; i++){
            Occ_days += (intervals[i][1] - intervals[i][0] + 1);
        }
        return days - Occ_days;
    }
};