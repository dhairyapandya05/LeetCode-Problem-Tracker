class Solution {
public:
    int cnt = 0;
    bool isSafe(int i, int j, vector<vector<char>>& grid) {
        return i >= 0 and i < grid.size() and j >= 0 and j < grid[0].size();
    }
    void solve(int i, int j, vector<vector<char>>& grid) {
        if (!isSafe(i, j, grid) or grid[i][j] == '$' or grid[i][j] == '0') {
            return;
        }
        // cnt++;
        grid[i][j] = '$'; // marking this particular land as visited
        solve(i + 1, j, grid);
        solve(i - 1, j, grid);
        solve(i, j + 1, grid);
        solve(i, j - 1, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    count++;
                    solve(i, j, grid);
                }
            }
        }
        return count;
    }
};