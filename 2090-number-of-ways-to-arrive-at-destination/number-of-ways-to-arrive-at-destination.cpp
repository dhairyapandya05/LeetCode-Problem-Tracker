class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long int MOD = 1e9 + 7;
        unordered_map<long long, vector<pair<long long, long long>>> adj;
        for (auto it : roads) {
            long long u = it[0];
            long long  v = it[1];
            long long w = it[2];
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
        }

        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>>
            pq;
        pq.push({0, 0});
        vector<long long> shortestPath(n,0);
        for (int i = 1; i < n; i++)
            shortestPath[i] = LLONG_MAX;
        vector<long long> ways(n, 0);
        ways[0] = 1;

        while (!pq.empty()) {
            auto tp = pq.top();
            pq.pop();
            long long wt = tp[0];
            long long u = tp[1];
            for (auto it : adj[u]) {
                long long wtg = it.first;
                long long adjNode = it.second;
                if (wt + wtg < shortestPath[adjNode]) {
                    shortestPath[adjNode] = wt + wtg;
                    ways[adjNode] = ways[u];
                    vector<long long> temp={shortestPath[adjNode], adjNode};
                    pq.push(temp);
                } else if (wt + wtg == shortestPath[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[u]) % MOD;
                }
            }
        }
        return ways[n - 1];
    }
};