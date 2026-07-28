class Solution {
public:
    typedef long long ll;

    ll EntranceCost(ll i, ll j){
        return (i+1)*(j+1);
    }

    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        
        vector<vector<vector<ll>>> dist(m, vector<vector<ll>>(n, vector<ll>(2,LLONG_MAX))) ; 
        vector<int> rdRow = {0,1};
        vector<int> rdCol = {1,0};
        vector<int> luRow = {0,-1};
        vector<int> luCol = {-1,0};

        ll ans ;
        priority_queue< tuple<ll,int,int,int>, vector<tuple<ll,int,int,int>> , greater<tuple<ll,int,int,int>>> pq; // {cost,i,j, action}

        pq.push({1,0,0,1});
        dist[0][0][1] = 1;

        while(!pq.empty()){
            auto [cost , r, c, action] = pq.top();
            pq.pop();

            if(cost > dist[r][c][action]) continue;
            if(r==m-1 && c==n-1){
                ans = cost;
                break;
            }
            // wait at the cell
            if(action == 1){
                if(cost+penalty[r][c] < dist[r][c][0]){
                    dist[r][c][0] = cost + penalty[r][c];
                    pq.push({cost+penalty[r][c] , r, c, 0});
                }
                
            }
            else{
                if(cost+penalty[r][c] < dist[r][c][1]){
                    pq.push({cost+penalty[r][c] , r, c, 1});
                    dist[r][c][1] = cost + penalty[r][c];
                }
            }

            // move right and down
            for(int i=0 ; i<2 ; i++){
                int nr = r + rdRow[i];
                int nc = c + rdCol[i];

                if(nr<m && nc<n && nr>=0 && nc>=0){
                    if(action == 1){
                        ll new_cost = cost + EntranceCost(nr,nc);
                        if(new_cost < dist[nr][nc][0]){
                            pq.push({new_cost , nr,nc ,0});
                            dist[nr][nc][0] = new_cost;
                        }
                    }
                    else{
                        ll new_cost = cost + EntranceCost(nr,nc) + penalty[r][c];
                        if(new_cost < dist[nr][nc][1]){
                            pq.push({new_cost , nr,nc ,1});
                            dist[nr][nc][1] = new_cost;
                        }
                    }
                }
            }
            // move left and up
            for(int i=0 ; i<2 ; i++){
                int nr = r + luRow[i];
                int nc = c + luCol[i];

                if(nr<m && nc<n && nr>=0 && nc>=0){
                    if(action == 0){
                        ll new_cost = cost + EntranceCost(nr,nc);
                        if(new_cost < dist[nr][nc][1]){
                            pq.push({new_cost , nr,nc ,1});
                            dist[nr][nc][1] = new_cost;
                        }
                    }
                    else{
                        ll new_cost = cost + EntranceCost(nr,nc) + penalty[r][c];
                        if(new_cost < dist[nr][nc][0]){
                            pq.push({new_cost , nr,nc ,0});
                            dist[nr][nc][0] = new_cost;
                        }
                    }
                }
            }
        }
        return ans;
    }
};