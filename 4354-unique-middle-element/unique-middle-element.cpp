class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int mid = n/2 ;

        int element = nums[mid];
        int count = 0;
        for(int num : nums){
            if(num == element) count++;
        }
        if(count > 1) return false;
        return true;
        
    }
};