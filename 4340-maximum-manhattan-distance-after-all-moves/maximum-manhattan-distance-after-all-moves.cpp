class Solution {
public:
    int maxDistance(string moves) {
        int hmov = 0;
        int vmov = 0;

        int unknown = 0;
        for(char ch: moves){
            if(ch == 'U'){
                vmov++;
            }
            else if(ch == 'D'){
                vmov--;
            }
            else if(ch == 'L'){
                hmov--;
            }
            else if(ch=='R'){
                hmov++;
            }
            else{
                unknown++;
            }
        }
        return abs(hmov)+abs(vmov)+unknown;
    }
};