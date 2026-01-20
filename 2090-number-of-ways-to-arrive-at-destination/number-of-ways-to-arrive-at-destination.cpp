class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        const int mod = 1e9 + 7;

        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<long long> dist(n, (long long)4e18);
        vector<long long> ways(n, 0);

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            if (cost > dist[node]) continue;

            for (auto it : adj[node]) {
                int nnode = it.first;
                long long ncost = it.second + cost;

                if (ncost < dist[nnode]) {
                    dist[nnode] = ncost;
                    ways[nnode] = ways[node];
                    pq.push({ncost, nnode});
                } else if (ncost == dist[nnode]) {
                    ways[nnode] += ways[node];
                    ways[nnode] %= mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};