class Solution {
public:
    bool canTransform(vector<int>& nums,vector<vector<int>>& queries, int k ){
        int n = nums.size();
        vector<int> diff(n,0);

        for(int i=0 ; i<=k ; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int x = queries[i][2];

            diff[l] += x;

            if(r+1 < n){
                diff[r+1] -= x;
            }
        }

        int cumsum = 0;
        for(int i=0 ; i<n ; i++){
            cumsum += diff[i];

            diff[i] = cumsum;

            if(nums[i]-diff[i] > 0) return false;
        }
        return true;

    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        
        auto lambda = [](int x){
            return x==0;
        };
        if(all_of(begin(nums), end(nums), lambda)){
            return 0;
        }
        int low = 0;
        int high = q-1 ;
        int result = -1 ;
        while(low <= high){
            int mid = low + (high-low)/2 ;

            if(canTransform(nums,queries, mid)){
                result = mid+1;
                high = mid - 1;
            }
            else{
                low = mid+1;
            }
        }
        return result;
    }
};