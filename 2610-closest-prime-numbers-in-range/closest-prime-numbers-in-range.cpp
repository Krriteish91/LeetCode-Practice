class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> prime(right + 1, true);

        prime[0] = false;
        prime[1] = false;

        for (int i = 2; i * i <= right; i++) {
            if (!prime[i])
                continue;

            for (int j = i * i; j <= right; j += i)
                prime[j] = false;
        }

        vector<int> res;
        for (int p = left; p <= right; p++){
            if (prime[p]){ 
                res.push_back(p);
            }
        }
        int ans1 = -1;
        int ans2 = -1;
        int diff = INT_MAX;
        for(int i=1 ; i<res.size() ; i++){
            if(res[i] - res[i-1] < diff){
                ans1 = res[i];
                ans2 = res[i-1];
                diff = ans1-ans2;
            }
        }

        return {ans2,ans1};

        
    }
};