class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();

        int i=0 , j=0;
        int res = 0;

        vector<int> freq(26,0);

        while(i<n && j < n){
            freq[s[j]-'a']++;

            while(i<n && freq[s[j]-'a'] > 2){
                freq[s[i]-'a']--;
                i++;
            }

            res = max(res, (j-i+1));
            j++;
        }
        return res;
    }
};