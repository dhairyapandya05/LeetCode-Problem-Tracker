class Solution {
    // Checks whether moving from column i to column j is valid
    // i.e., for every string, character at i <= character at j
    bool isIndexGood(int i, int j, vector<string>& strs) {
        for (int k = 0; k < strs.size(); k++) {
            if (i >= 0 && j < strs[k].length() && strs[k][i] > strs[k][j]) {
                return false;
            }
        }
        return true;
    }

    // Recursive DP function
    // i = last chosen column index
    int solve(int i, vector<string>& strs, int maxi, vector<int>& dp) {
        // If we are past the last column, no deletions needed
        if (i >= maxi) {
            return 0;
        }

        // Memoization (shifted by +1 because i can be -1)
        if (dp[i + 1] != -1) {
            return dp[i + 1];
        }

        int ans = INT_MAX;

        // Try choosing the next column j
        for (int j = i + 1; j <= maxi; j++) {
            if (isIndexGood(i, j, strs)) {
                // Columns between i and j are deleted
                ans = min(ans, solve(j, strs, maxi, dp) + (j - i - 1));
            }
        }

        return dp[i + 1] = ans;
    }

public:
    int minDeletionSize(vector<string>& strs) {
        int maxi = 0;

        // Find maximum column length
        for (auto& s : strs) {
            maxi = max(maxi, (int)s.length());
        }

        // dp[i+1] stores answer for solve(i)
        vector<int> dp(maxi + 1, -1);

        // Start with no column selected (i = -1)
        return solve(-1, strs, maxi, dp);
    }
};