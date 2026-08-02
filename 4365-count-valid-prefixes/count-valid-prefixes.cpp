class Solution {
public:
    int countValidPrefixes(string s) {
        int n = s.size();

        unordered_map<char,int> freq;
        int ans = 0;
        for(int i=0 ; i<n ; i++){
            freq[s[i]]++;

            if(abs(freq['0'] - freq['1']) <= 1 ){
                ans++ ;
            }
        }
        return ans;
    }
};