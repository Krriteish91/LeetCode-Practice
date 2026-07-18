class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int K) {

        vector<vector<pair<int, int>>> adj(n);

        sort(edges.begin(), edges.end());

        for (int i = 0; i < edges.size(); i++) {

            if (i > 0 && edges[i][0] == edges[i - 1][0] &&
                edges[i][1] == edges[i - 1][1])
                continue;

            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }

        const long long INF = 1e18;

        vector<vector<long long>> dist(n, vector<long long>(K + 1, INF));

        using pp = tuple<long long, int, int>;
        priority_queue<pp, vector<pp>, greater<pp>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {

            auto [d, u, cnt] = pq.top();
            pq.pop();

            if (d != dist[u][cnt])
                continue;

            for (auto& [v, w] : adj[u]) {

                int newCnt = (labels[u] == labels[v]) ? cnt + 1 : 1;

                if (newCnt > K)
                    continue;

                long long nd = d + w;

                if (nd < dist[v][newCnt]) {

                    dist[v][newCnt] = nd;

                    pq.push({nd, v, newCnt});
                }
            }
        }

        long long ans = INF;

        for (int cnt = 1; cnt <= K; cnt++)
            ans = min(ans, dist[n - 1][cnt]);

        return ans == INF ? -1 : (int)ans;
    }
};