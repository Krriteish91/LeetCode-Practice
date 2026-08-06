class Solution {
public:
    bool divisible(int num, int t){
        int sum = 1;
        
        while(num >0){
            sum *= (num % 10);
            num /= 10;
        }
        
        if(sum % t == 0) return true;
        return false;
    }
    int smallestNumber(int n, int t) {
        int low = n;
        int high = 100;
        int ans ;
        while(low<=high){
            if(divisible(low,t)) return low;
            low++;
        }
        return ans;
    }
};