class Solution {
public:
    void numberofislands(vector<vector<int>>& matrix,int i,int j){
        if(i<0 or j<0 or i>=matrix.size() or j>=matrix[0].size() or matrix[i][j]==1 ) return;

        matrix[i][j]=1; // marking them as visited
        numberofislands(matrix,i+1,j);
        numberofislands(matrix,i-1,j);
        numberofislands(matrix,i,j+1);
        numberofislands(matrix,i,j-1);

    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> matrix(n * 3, vector<int>(m * 3, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '/') {
                    matrix[i * 3][j * 3 + 2] = 1;
                    matrix[(i * 3) + 1][(j * 3) + 1] = 1;
                    matrix[(i * 3) + 2][j * 3] = 1;
                } else if (grid[i][j] == '\\') {
                    matrix[i * 3][j * 3] = 1;
                    matrix[(i * 3) + 1][(j * 3) + 1] = 1;
                    matrix[i * 3 + 2][(j * 3) + 2] = 1;
                }
            }
        }
        n=matrix.size();
        m=matrix[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    numberofislands(matrix,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};