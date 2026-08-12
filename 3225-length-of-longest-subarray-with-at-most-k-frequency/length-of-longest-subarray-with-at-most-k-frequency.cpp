class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        map<int,int> freq;

        int result = 1;
        int i=0,j=1;

        freq[nums[0]]++;

        while(i<n && j<n){

            while(j<n && freq.begin()->second <= k ){

                if(freq[nums[j]] + 1 > k){
                    break;
                }
                result = max(result, (j-i+1));
                freq[nums[j]]++;
                j++;
            }
            freq[nums[i]]--;
            i++;
        } 
        return result;       
    }
};