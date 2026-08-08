class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> length_matched_rhs(n+1,0);

        int j = m-1;
        for(int i=n-1 ; i>=0 ; i--){
            if(j<0){
                length_matched_rhs[i] = length_matched_rhs[i+1];
                continue;
            }
            if(word1[i] == word2[j]){
                
                length_matched_rhs[i] = length_matched_rhs[i+1] + 1;
                j--;
            }
            else{

                length_matched_rhs[i] = length_matched_rhs[i+1];

            }
        }

        bool canChange = true;
        int i = 0;
        j=0;

        vector<int> ans ; 

        while(i<n && j<m){
            if(word1[i] != word2[j]){
                if(canChange && length_matched_rhs[i+1] >= (m-(j+1))){
                    canChange = false;
                    ans.push_back(i);
                    i++;
                    j++;
                }
                else{
                    i++;
                }
            }
            else{
                ans.push_back(i);
                i++;
                j++;
            }
            if(ans.size() == m) break;

        }
        if(ans.size() != m) return {};
        return ans;
    }
};