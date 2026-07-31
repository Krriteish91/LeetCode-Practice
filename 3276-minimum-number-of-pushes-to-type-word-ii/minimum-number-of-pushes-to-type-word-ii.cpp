class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> count(26,0);

        for(char ch: word){
            count[ch-'a']++;
        }
        int ans = 0;
        priority_queue<int> pq;

        for(int i=0 ; i<26 ; i++){
            if(count[i]>0)
            pq.push(count[i]);
        }
        int unique_char = 0;
        while(!pq.empty()){
            int freq = pq.top();
            pq.pop();
            unique_char++;

            if(unique_char <= 8){
                ans += freq;
            }
            else if( unique_char > 8 && unique_char <= 16){
                ans += (freq*2);
            }
            else if( unique_char > 16 && unique_char <= 24){
                ans += (freq*3);
            }
            else{
                ans += (freq*4);
            }
        }
        return ans;
    }
};