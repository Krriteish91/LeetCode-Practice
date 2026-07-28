class Solution {
public:
    string smallestPalindrome(string s) {
        int n =  s.size();

        vector<int> freq(26,0);
        for( char c : s){
            freq[c-'a']++;
        }
        string ans(n,'#');
        for(int i=0 ; i<=(n-1)/2 ; i++){
            for(int j=0 ; j<26 ; j++){
                if(freq[j]>1){
                    ans[i] = 'a'+j;
                    ans[n-i-1] = 'a'+j;
                    freq[j] -= 2;
                    break;
                }
                else if(n%2 == 1 && i==n/2 && freq[j]>0){
                    ans[i] = 'a'+j;
                    freq[j]--;
                    break;
                }
            }
        }
        return ans;
    }
};