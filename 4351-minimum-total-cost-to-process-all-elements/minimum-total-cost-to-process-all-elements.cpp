class Solution {
public:
    typedef long long ll;
    ll mod = 1e9+7;
    int minimumCost(vector<int>& nums, int k) {
        int n = nums.size();
        ll res = k;
        ll price = 0;
        ll cost = 0;
        int i=0;

        while(i<n){
            if( res >= nums[i]){
                res -= nums[i];
            }
            else{
                ll steps = ceil(static_cast<double>(nums[i]-res)/k);
                cost += (((steps%mod)*((2*(price+1) + (steps-1))%mod))/2)%mod;
                price = price+1 + (steps-1);
                res += (steps*k);
                res -= nums[i];
                cost = cost%mod;
            }
            i++;
        }
        return cost;
    }
};