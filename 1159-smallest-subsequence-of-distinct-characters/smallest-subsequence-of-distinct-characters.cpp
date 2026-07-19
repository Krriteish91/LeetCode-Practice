class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<int> lastOcc(26,-1);

        for(int i=0 ; i<n ; i++){
            lastOcc[s[i]-'a'] = i;
        }
        vector<int> vis(26,0);

        stack<char> st;

        for(int i=0 ; i< n ; i++){
            char ch = s[i];
            if(vis[ch-'a']) continue;

            while(!st.empty() && st.top() > ch && lastOcc[st.top()-'a'] > i){
                vis[st.top()-'a'] = 0;
                st.pop();
            } 
            st.push(ch);
            vis[ch-'a'] = 1;
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};