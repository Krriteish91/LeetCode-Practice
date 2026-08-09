class Solution {
public:
    int dfs(int node,vector<vector<int>>& adj){
        
        int h = 0;

        for(int nbr : adj[node] ){
            h = max(h ,1+ dfs(nbr,adj));
        }
        return h;
    }
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();

        vector<vector<int>> adj(n);

        for(int i=1 ; i<n ; i++){
            adj[parent[i]].push_back(i);
        }
        int h =1+ dfs(0,adj);
        cout << h;
        long long cost = 0;

        queue<pair<int,int>> q;
        q.push({0,1});
        
        while(!q.empty()){
            int node = q.front().first;
            int d = q.front().second;
            q.pop(); 

            cost = cost + 1LL*nums[node]*(h-d+1)*1LL ;

            for(int nbr : adj[node]){
                q.push({nbr,d+1});
            }
        }
        return cost;
    }
};