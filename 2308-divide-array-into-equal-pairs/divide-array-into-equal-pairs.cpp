class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int i=0 ; i<nums.size() ; i++){
            mpp[nums[i]]++;
        }

        for(auto [num,cnt]: mpp){
            if(cnt%2 == 1) return false;
        }
        return true;
    }
};