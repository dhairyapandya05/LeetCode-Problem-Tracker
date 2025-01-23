class Solution {
public:
    typedef long long ll;
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        ll ans = 0;
        vector<ll> incols(m, 0);
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            int temp = -1;
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    cnt++;
                    incols[j]++;
                    temp = j;
                }
            }
            if (cnt > 1) {
                ans += cnt;
            } 
          else if (cnt == 1) {
                incols[temp]--; 
                // Decrement incols[temp] instead of setting to 0, e.g.,
                // for grid = {{1, 1}, {0, 1}}, incols[1] = 2 after row 0.
                // But since row 1 has a single server, column 1's count is reduced.
            }
        }
        for (int j = 0; j < m; j++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (grid[i][j]) {
                    cnt++;
                    
                   
                }
            }
          if(cnt>1)
           ans+=cnt-incols[j];
        }
        return ans;
    }
};