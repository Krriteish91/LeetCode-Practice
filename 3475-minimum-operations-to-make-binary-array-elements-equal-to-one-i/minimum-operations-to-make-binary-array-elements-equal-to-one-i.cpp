class Solution {
public:
    
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        int cnt = 0;
        for(int i=0 ; i<n-2 ; i++){
            if(nums[i] == 0){
                cnt++;
                nums[i] = 1;
                if(nums[i+1] == 0) nums[i+1]=1;
                else nums[i+1] = 0;
                if(nums[i+2] == 0) nums[i+2]=1;
                else nums[i+2] = 0;
                
            }
        }
        if(count(begin(nums),end(nums),0) > 0) return -1;
        return cnt;
    }
};