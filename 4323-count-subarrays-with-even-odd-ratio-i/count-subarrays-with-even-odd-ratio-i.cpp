class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        
        int n = nums.size();
        double threshold = (a*1.0)/(b*1.0);

        int count = 0 ;

        for(int i=0 ; i<n ; i++){
            double even = 0;
            double odd = 0;

            for(int j=i ; j<n ; j++){
                if(nums[j]%2 == 1) odd = odd + 1.0;
                else even = even + 1.0;

                if(odd > 0.0){
                    double ratio = even/odd;

                    if(ratio <= threshold) count++ ;

                }

            }
        }
        return count;
    }
};