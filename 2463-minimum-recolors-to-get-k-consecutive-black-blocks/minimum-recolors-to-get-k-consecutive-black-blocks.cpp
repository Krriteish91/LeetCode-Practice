class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i=0 , j=0 ;
        int n = blocks.size();

        int ans = INT_MAX;
        int white = 0;
        int black = 0;
        while(j<n){

            char ch = blocks[j];

            if(j-i+1 <= k){

                if(ch=='W'){
                    white++;
                }
                else{
                    black++;
                }
                if(j-i+1 == k){
                    ans= min(ans,white);
                    char c = blocks[i];
                    if(c=='W'){
                        white--;
                    }
                    else{
                        black--;
                    }
                    i++;
                }
                j++;
            }

        }
        return ans;
    }
};