class Solution {
public:
    bool isValid(string s) {
        int n= s.size();
        stack<char> st;
        int i=0;
        while(i<=n){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
                
            }
            
            if(s[i]==')'){
                if(!st.empty() && st.top()=='(') st.pop();
                else st.push(s[i]);                
            }
            else if(s[i]=='}'){
                if(!st.empty() && st.top()=='{') st.pop();
                else st.push(s[i]);
                
            }
            else if(s[i]==']'){
                if(!st.empty() && st.top()=='['){
                    st.pop();
                
                }
                else st.push(s[i]);
                
            }
            i++;
        }
        if(st.empty()) return true;
        return false;
    }
};