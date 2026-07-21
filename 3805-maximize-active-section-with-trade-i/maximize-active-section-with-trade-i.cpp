class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();

        int ones = count(begin(s),end(s),'1');
        vector<int> zeroBlocks;
        int i=0 ; 
        while(i<n){
            if(s[i] == '0'){
                int start = i;
                while(i<n && s[i]=='0') i++;

                zeroBlocks.push_back(i-start);
            }
            else{
                i++;
            }
        }
        if(zeroBlocks.size() == 0) return ones;
        int max_zeros = 0;
        for(int i=0 ; i<zeroBlocks.size()-1 ; i++){
            max_zeros = max(max_zeros,zeroBlocks[i]+zeroBlocks[i+1] );
        }
        return ones+max_zeros;
    }
};