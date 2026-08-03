class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        long long result = 0;

        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){

                long long a = nums[i];
                long long b = nums[j];
                long long g = gcd(a,b);
                long long s = (a*b)/(g*g);
                result = max(result , s );
            }
        }
        return result;
    }
};