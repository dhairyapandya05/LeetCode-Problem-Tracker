class Solution {
public:
    int n, m;
    vector<vector<int>> dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    bool isSafe(int i, int j) { return i >= 0 and j >= 0 and i < n and j < m; }
    void dfs(vector<vector<int>>& grid, int i, int j,
             set<pair<int, int>>& visitedCell) {
        if (!isSafe(i, j) or grid[i][j] == 0 or
            visitedCell.find({i, j}) != visitedCell.end()) {
            return;
        }
        visitedCell.insert({i, j});
        for (auto d : dir) {
            dfs(grid, i + d[0], j + d[1], visitedCell);
        }
    }

    int bfs(vector<vector<int>>& grid, set<pair<int, int>>& visitedCell) {
        queue<pair<int, int>> qe;
        for (auto it : visitedCell) {
            qe.push(it);
        }
        int level = 0;
        while (!qe.empty()) {
            int l = qe.size();
            while (l--) {
                auto p = qe.front();
                qe.pop();
                int x = p.first;
                int y = p.second;
                for (auto d : dir) {
                    int x_=x+d[0];
                    int y_=y+d[1];
                    if (isSafe(x_, y_) and
                        visitedCell.find({x_, y_}) == visitedCell.end()) {
                        if (grid[x_][y_] == 1)
                            return level;
                        
                        visitedCell.insert({x_,y_});
                        qe.push(make_pair(x_,y_));
                    }
                    
                }
            }
            level++;
        }
        return level;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        set<pair<int, int>> visitedCell;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, visitedCell);
                    return bfs(grid, visitedCell);
                }
            }
        }
        return -1;
    }
};