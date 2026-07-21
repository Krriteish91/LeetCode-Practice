class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<vector<int>> adj(n);
        for(auto it: edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = INT_MIN;
        for(int i=0 ;i<n;i++){
            int sum = vals[i];
            ans = max(ans,sum);
            priority_queue<int,vector<int>, greater<int>> pq;
            for(int nbr: adj[i]){
                if (vals[nbr] <= 0)
                    continue;
                pq.push(vals[nbr]);
                sum += vals[nbr];
                if(pq.size()>k){
                    sum -= pq.top();
                    pq.pop();
                }
                ans = max(ans,sum);
            }
            
        }
        return ans;
    }
};