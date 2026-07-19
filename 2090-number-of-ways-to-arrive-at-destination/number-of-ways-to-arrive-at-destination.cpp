class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto it : roads){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        long long mod = 1e9+7 ;
        vector<long long> dist(n,LLONG_MAX);
        vector<long long> path(n,0);

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> q;
        q.push({0,0});
        dist[0] = 0;
        path[0] = 1;

        while(!q.empty()){
            auto [time ,node] = q.top();
            q.pop();
            if (time != dist[node]) continue;
            for(auto [nbr, t]: adj[node]){
                
                long long new_time = time+t;

                if(new_time<dist[nbr]){
                    dist[nbr] = new_time;
                    path[nbr] = path[node];
                    q.push({new_time,nbr});
                }
                else if(new_time == dist[nbr]){
                    path[nbr] = (path[nbr]+path[node])%mod;
                    
                }
            }
        }
        return path[n-1];
    }
};