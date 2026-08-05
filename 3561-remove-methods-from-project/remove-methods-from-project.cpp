class Solution {
public:
    void dfs(int node ,vector<vector<int>> &adj,vector<int>& suspicious  ){
        suspicious[node] = 1;

        for(int nbr: adj[node]){
            if(!suspicious[nbr]){
                dfs(nbr,adj,suspicious);
            }
        }
    }
    bool dfs_check(int node ,vector<vector<int>> &adj, vector<int>& vis ,vector<int>& suspicious){
        vis[node] = 1;

        if(suspicious[node] == 1) return true;

        for(int nbr: adj[node]){
            if(!vis[nbr]){
                if(dfs_check(nbr,adj,vis,suspicious)){
                    suspicious[node] = 1;
                    return true;
                }
            }
        }
        return false;
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        int s = invocations.size();

        vector<vector<int>> adj(n);
        vector<int> suspicious(n,0);

        for(int i=0 ; i<s ; i++){
            int u = invocations[i][0];
            int v = invocations[i][1];

            adj[u].push_back(v);
        }
        dfs(k,adj,suspicious);
        vector<int> res;

        for(int i=0 ; i<n ; i++){
            if(suspicious[i] == 0){
                res.push_back(i);
            }
        }
        if(res.size() == 0) return {};

        vector<int> vis(n,0);

        bool canRemove = true;

        for(int i=0 ; i<n ; i++){
            if(!vis[i] && !suspicious[i]){
                if(dfs_check(i,adj,vis,suspicious)){
                    suspicious[i] = 1;
                    canRemove = false;
                }
            }
        }
        vector<int> methods;
        for(int i=0 ; i<n ; i++){
            methods.push_back(i);
        }
        if(canRemove == false) return methods;

        vector<int> ans1;
        for(int i=0 ; i<n ; i++){
            if(suspicious[i] == 0){
                ans1.push_back(i);
            }
        }
        
        return ans1;


    }
};