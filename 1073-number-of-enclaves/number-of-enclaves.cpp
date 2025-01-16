class Solution {
public:
    int n,m;
        
    void dfs (vector<vector<int>>&grid,int i,int j){
        grid[i][j]=0;
        if(i-1>=0 and grid[i-1][j]==1){
            dfs(grid,i-1,j);
        }
        if(j-1>=0 and grid[i][j-1]==1){
            dfs(grid,i,j-1);
        }
        if(i+1<n and grid[i+1][j]==1){
            dfs(grid,i+1,j);
        }
        if(j+1<m and grid[i][j+1]==1){
            dfs(grid,i,j+1);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        for(int row=0;row<n;row++){
            if(grid[row][0]==1){
                dfs(grid,row,0);
            }
            if(grid[row][m-1]==1){
                dfs(grid,row,m-1);
            }
        }


        for(int col=0;col<m;col++){
            if(grid[0][col]==1){
                dfs(grid,0,col);
            }
            if(grid[n-1][col]==1){
                dfs(grid,n-1,col);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) 
                    count++;
            }
        }
        return count;
    }
};