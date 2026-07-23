class Solution {
public:
    bool canRepair(long long time, vector<int>& ranks, int cars){
        long long cnt=0; 

        for(int i=0 ; i<ranks.size() ; i++){
            cnt += sqrt(time/ranks[i]);
        }
        if(cnt >= cars) return true;
        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1;
        int maxR = *max_element(ranks.begin(),ranks.end());
        long long high = 1LL * maxR * cars * cars;

        long long result = -1;
        while(low<=high){
            long long mid = low + (high-low)/2 ;
            if(canRepair(mid,ranks,cars)){
                result = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return result;
    }
};