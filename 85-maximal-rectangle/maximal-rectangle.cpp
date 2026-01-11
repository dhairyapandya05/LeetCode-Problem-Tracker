class Solution {
public:
    int maximalRectangle(vector<vector<char>>& M) {
        if(!size(M)) return 0;
        int ans = 0, m = size(M), n = size(M[0]);
      
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for(int i = m-1; i>=0; i--)
            for(int j = n-1; j>=0; j--)
                dp[i][j] = M[i][j] == '1' ? dp[i][j+1] + 1 : 0;
                  
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int minWidth = INT_MAX;

                for (int r = i; r < m && M[r][j] == '1'; r++) {
                    minWidth = min(minWidth, dp[r][j]);
                    int height = r - i + 1;
                    ans = max(ans, height * minWidth);
                }
            }
        }
        return ans;
    }  
};