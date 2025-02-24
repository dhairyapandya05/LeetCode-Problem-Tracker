/**
 * Approach - Using DFS for Bob and Alice
 * Time Complexity : O(n)
 * Space Complexity : O(n) (for recursion stack and adjacency list)
 */

class Solution {
public:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> bobMap;
    int aliceIncome;

    // DFS for Bob to record the time taken to reach each node
    bool DFSBob(int curr, int t, vector<bool>& visited) {
        visited[curr] = true;
        bobMap[curr] = t;  // Store time taken to reach this node

        if (curr == 0)  // Reached root
            return true;

        for (auto &ngbr : adj[curr]) {
            if (!visited[ngbr]) {
                if (DFSBob(ngbr, t + 1, visited))
                    return true;
            }
        }

        bobMap.erase(curr);  // Remove node if it's not in the shortest path
        return false;
    }

    // DFS for Alice to maximize profit
    void DFSAlice(int curr, int t, int income, vector<bool>& visited, vector<int>& amount) {
        visited[curr] = true;

        if (bobMap.find(curr) == bobMap.end() || t < bobMap[curr]) {
            income += amount[curr];  // Alice gets full profit if Bob is not there yet
        } else if (t == bobMap[curr]) {
            income += (amount[curr] / 2);  // Split profit if they arrive at the same time
        }

        // If current node is a leaf node, update maximum profit
        if (adj[curr].size() == 1 && curr != 0) {
            aliceIncome = max(aliceIncome, income);
        }

        // Explore neighbors
        for (int &ngbr : adj[curr]) {
            if (!visited[ngbr]) {
                DFSAlice(ngbr, t + 1, income, visited, amount);
            }
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size(); // Number of nodes

        aliceIncome = INT_MIN;
        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // DFS on Bob to determine his path to node 0
        int time = 0;
        vector<bool> visited(n, false);
        DFSBob(bob, time, visited);
        
        // DFS for Alice to maximize profit
        int income = 0;
        visited.assign(n, false);
        DFSAlice(0, 0, income, visited, amount);

        return aliceIncome;
    }
};