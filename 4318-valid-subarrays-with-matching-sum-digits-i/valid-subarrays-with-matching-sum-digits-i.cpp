class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();

        int count = 0;
        for(int i=0 ; i<n ; i++){
            long long sum = nums[i];

            // string num = to_string(sum);
            // char digit = x + '0';

            // if(num[0]== digit && num.back()==digit) count++;

            if(sum % 10 == x && to_string(sum)[0] - '0' == x ){
                count ++;
            }

            for(int j= i+1 ; j<n ; j++){

                sum += nums[j];
                // cout << sum << endl;
                // string hum = to_string(sum);
                if(sum % 10 == x && to_string(sum)[0] - '0' == x ){
                count ++;
            }

            }
        }
        return count;

    }
};