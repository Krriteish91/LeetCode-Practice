class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        
        int sumOdd = n*n;
        int sumEven = n*n + n;

        return gcd(sumOdd, sumEven);
    }
};