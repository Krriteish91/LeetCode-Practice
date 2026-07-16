class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        long long maxn = 0;
        vector<long long> prefixGcd(n);
        for(int i=0 ; i<n ; i++){
            maxn = max((long long)nums[i],maxn);
            prefixGcd[i] = gcd(maxn , nums[i]);
        }
        sort(prefixGcd.begin()  , prefixGcd.end());
        int i=0 , j=n-1 ;
        long long sum = 0;
        while( i<j ){
            sum += gcd(prefixGcd[i] , prefixGcd[j]);
            i++;
            j--;
        }
        return sum;
    }
};