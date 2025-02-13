class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<int> freqRows(n,0);
        vector<int> freqCols(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    freqRows[i]++;
                    freqCols[j]++;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 and (freqRows[i]>=2 or freqCols[j]>=2)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};