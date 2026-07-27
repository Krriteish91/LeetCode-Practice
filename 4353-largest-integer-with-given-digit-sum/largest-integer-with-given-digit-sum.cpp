class Solution {
public:
    int power(int n,int p){
        int num = 1;
        for(int i=1 ; i<=p ; i++){
            num *= n;
        }
        cout << "power" << endl;
        return num;
    }
    int sumOfDigits(int n){
        int sum = 0;

        while( n > 0 ){
            sum += (n%10);
            n = n/10;
        }
        cout << "sumofdigits" <<endl;
        return sum;
    }
    int largestInteger(int n, int s) {
        if(s > 9*n) return -1;
        if(s==0) return 0;

        int num = power(10,n) -1 ;
        for(int i=num ; i>=1 ; i--){
            int sum = sumOfDigits(i);
            if(sum == s){
                return i;
            }
        }
        return -1;
    }
};