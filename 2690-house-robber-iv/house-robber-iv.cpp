class Solution {
public:
    bool canSteal(int cap ,int k, vector<int>& nums){
        int houseRobbed = 0;

        int i=0 ; 
        while(i< nums.size()){
            if(nums[i]<= cap) {
                houseRobbed++;
                i += 2;
            }
            else i++;
        }
        return houseRobbed >= k;
    }
    int minCapability(vector<int>& nums, int k) {

        int low = *min_element(begin(nums),end(nums));
        int high = *max_element(begin(nums),end(nums));
        int result ;
        while(low <= high){
            int mid = low+(high-low)/2;

            if(canSteal(mid,k,nums)){
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