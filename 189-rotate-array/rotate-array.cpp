class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int d = k % n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(), nums.begin()+d);
        reverse(nums.begin()+d , nums.end());
        
    }
};