class Solution {
public:
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool isSafe(int i, int j, vector<vector<int>>& mat) {
        return i >= 0 and i < mat.size() and j >= 0 and j < mat[0].size();
    }
    int dfs(int i, int j, vector<vector<int>>& matrix,
            vector<vector<int>>& dp) {
        if (dp[i][j] != -1)
            return dp[i][j]; // Return cached result

        int res = 1;
        for (auto it : dir) {
            int nexi = i + it.first;
            int nexj = j + it.second;
            if (isSafe(nexi, nexj, matrix) and
                matrix[nexi][nexj] > matrix[i][j]) {
                res = max(res, 1 + dfs(nexi, nexj, matrix, dp));
            }
        }
        return dp[i][j] = res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int maxans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                maxans = max(maxans, dfs(i, j, matrix, dp));
            }
        }
        return maxans;
    }
};