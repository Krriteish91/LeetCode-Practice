class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int , unordered_set<int>> mpp;

        for(int i=0 ; i<reservedSeats.size() ; i++){
            mpp[reservedSeats[i][0]].insert(reservedSeats[i][1]);
        }
        int count = 0;
        int cnt_row = 0;
        for(auto& [ row , seats] : mpp){
            cnt_row ++;
            if(seats.count(2) == 0 && seats.count(3)==0 && seats.count(4)==0 && seats.count(5)==0){
                    count++;
                    mpp[row].insert(4);
                    mpp[row].insert(5);
            } 
            if(seats.count(4)==0 && seats.count(5)==0  && seats.count(6)==0 && seats.count(7)==0){
                    count++;
                    mpp[row].insert(6);
                    mpp[row].insert(7);
            }
            
            if(seats.count(6)==0 && seats.count(7)==0 && seats.count(8)==0 && seats.count(9)==0) count++;
            
        }

        return count+2*(n-cnt_row);
    }
};