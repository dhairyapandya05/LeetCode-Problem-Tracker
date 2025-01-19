class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<vector<int>> qe;
        int steps = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '@') {
                    qe.push({i, j, steps, 0});
                } else if (grid[i][j] >= 'a' and grid[i][j] <= 'f') {
                    cnt++;
                }
            }
        }
        int finalkeycountstat = pow(2, cnt) - 1;
        int visited[n][m][finalkeycountstat + 1];
        memset(visited, 0, sizeof(visited));

        while (!qe.empty()) {
            auto temp = qe.front();
            qe.pop();
            int i = temp[0];
            int j = temp[1];
            int steps = temp[2];
            int currentkeystatus = temp[3];
            if (currentkeystatus == finalkeycountstat) {
                return steps;
            }
            for (auto& d : dir) {
                int newi = i + d[0];
                int newj = j + d[1];
                if (newi >= 0 and newj >= 0 and newi < n and newj < m and
                    grid[newi][newj] != '#') {
                    char ch = grid[newi][newj];
                    if (ch >= 'a' and ch <= 'f') { // We have found a key
                        int newkeystatus =
                            currentkeystatus | (1 << (ch - 'a'));
                        if (visited[newi][newj][newkeystatus] == 0) {
                            visited[newi][newj][newkeystatus] = 1;
                            qe.push({newi, newj, steps + 1, newkeystatus});
                        }
                    } else if (ch >= 'A' and
                               ch <= 'F') { // We have found a lock
                        if (visited[newi][newj][currentkeystatus] == 0 and
                            ((currentkeystatus >> (ch - 'A')) & 1) != 0) {
                            visited[newi][newj][currentkeystatus] = 1;
                            qe.push({newi, newj, steps + 1, currentkeystatus});
                        }
                    } else {
                        // it is equal to '.'
                        if (visited[newi][newj][currentkeystatus] == 0) {
                            visited[newi][newj][currentkeystatus] = 1;
                            qe.push({newi, newj, steps + 1, currentkeystatus});
                        }
                    }
                }
            }
        }

        return -1;
    }
};