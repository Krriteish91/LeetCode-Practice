class Solution {
public:
    vector<int> parent;
    vector<long long> size;
    vector<long long> cost;
    int findParent(int u){
        if(parent[u] == u) return u;

        return parent[u] = findParent(parent[u]);
    }
    void UnionBySize(int u , int v,int w){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        
        if(ulp_u == ulp_v){
            cost[ulp_u] &= w;
            cost[ulp_u] &= cost[ulp_v];
            return;
        }

        if(size[ulp_u] >= size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
            cost[ulp_u] &= w;
            cost[ulp_u] &= cost[ulp_v];

        }
        else{
            parent[ulp_u] = ulp_v ;
            size[ulp_v] += size[ulp_u];
            cost[ulp_v] &= w;
            cost[ulp_v] &= cost[ulp_u];
        }
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n+1);
        size.assign(n+2,1);
        cost.assign(n+1, INT_MAX);
        for(int i=0 ; i<=n ; i++){
            parent[i] = i;
        }
        
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            UnionBySize(u,v,w);
        }
        vector<int> ans;
        for(auto q:query){
            int u = q[0];
            int v = q[1];

            if(findParent(u) == findParent(v)){
                int ulp = findParent(u);
                ans.push_back(cost[ulp]);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};