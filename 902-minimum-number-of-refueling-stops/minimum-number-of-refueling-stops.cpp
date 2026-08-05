class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<pair<int,int>> pq;

        int dist = startFuel;
        int count = 0;
        int idx = 0;
        while(dist < target){



            while(idx < stations.size() && stations[idx][0] <= dist){
                pq.push({stations[idx][1], stations[idx][0]});
                idx++;
            }

            if(pq.empty()) return -1;

            int s = pq.top().second;
            int f = pq.top().first;
            pq.pop();
            dist = dist + f;
            count ++ ;
        }
        return count;
    }
};