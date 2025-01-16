class Solution {
public:
int n,m;
    bool dfs(vector<vector<int>>&grid,int i,int j){
        if(i>=n or i<0 or j<0 or j>=m) return false;
        if(grid[i][j]==1){
            return true;
        }
        grid[i][j]=1;
        bool leftclose=dfs(grid,i,j-1);
        bool rightclose=dfs(grid,i,j+1);
        bool topclose=dfs(grid,i-1,j);
        bool bottomclose=dfs(grid,i+1,j);
        return leftclose and rightclose and topclose and bottomclose;

    }
    int closedIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    if(dfs(grid,i,j)==true){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};