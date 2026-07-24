class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        unordered_map<char,int> freq;

        int j=0 ;
        int count = 0;
        int i=0 ;
        while(i<n && j<n){
            freq[s[j]]++;
            if(freq['a'] == 0 || freq['b'] == 0 || freq['c'] == 0){
                j++;
            }
            else{
                while(freq['a'] > 0 && freq['b'] > 0 && freq['c'] > 0){
                    count += (n-j);
                    freq[s[i]]--;
                    i++;
                }
                j++;
                freq[s[j]];
            }
        }
        return count;
    }
};