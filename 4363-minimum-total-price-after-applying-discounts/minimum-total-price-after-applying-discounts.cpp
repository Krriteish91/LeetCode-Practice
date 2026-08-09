class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin() , prices.end());
        sort(discounts.begin() ,discounts.end());

        int n = prices.size();
        int m = discounts.size();
        int p = n-1 , d = m-1 ; 
        double cost = 0.0 ;

        while( p >=0 ){
            double price = prices[p]*1.0;
            if(d >= 0){
                
                double disc = discounts[d]*1.0;

                cost += (price*(100 - disc))/100.0 ;
                p--;
                d--;
            }
            else{
                cost += price ;
                p--;
            }
        }
        return cost;
    }
};