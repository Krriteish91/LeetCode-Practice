class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> firstOcc(26,-1);
        vector<int> lastOcc(26,-1);

        for(int i=0 ; i<s.size() ; i++){
            if(firstOcc[s[i]-'a'] == -1){
                firstOcc[s[i]-'a'] = i;
            }

            lastOcc[s[i]-'a'] = i;
        }
        int ans = 0;
        for(int i=0 ; i<26 ; i++){
            if(lastOcc[i] == -1) continue;

            int start = firstOcc[i];
            int end = lastOcc[i];

            set<char> st;

            for(int j=start+1 ; j<end ; j++){
                st.insert(s[j]);
            }
            ans += st.size();
        }
        return ans;
    }
};