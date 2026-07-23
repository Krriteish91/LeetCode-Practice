class Solution {
public:
    
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;

        int nbits = 32 - __builtin_clz(n);

        return (1<<nbits) ;
    }
};