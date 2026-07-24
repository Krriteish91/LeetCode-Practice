class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> S;

        for(int i=0 ; i<n ; i++){
            for(int j=i ; j<n ; j++){
                S.insert(nums[i]^nums[j]);
            }
        }
        unordered_set<int> T;
        for(auto x : S){
            for(int i=0 ; i<n ; i++){
                T.insert(x^nums[i]);
            }
        }
        return T.size();
    }
};