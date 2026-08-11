class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int num:nums){
            mpp[num]++;
        }

        int n = nums.size();
        int max_len = 0 , ans= -1;
        int i=0;

        
        int sum = 0;

        int j = 0;

        while(j<n-1 && nums[j+1]-nums[j] == 1){
            sum += nums[j];
            j++;
        }
        sum += nums[j];

        if((j-i+1) > max_len){
            ans = sum;
            max_len = (j-i+1);
        }
            
        

        while(mpp.count(ans) > 0){
            ans++;
        }
         return ans;
    }
};