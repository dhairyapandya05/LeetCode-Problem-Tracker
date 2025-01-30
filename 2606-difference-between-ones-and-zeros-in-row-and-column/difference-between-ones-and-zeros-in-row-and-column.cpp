class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> row(n);
        vector<int> col(m);
        vector<vector<int>> diff( n , vector<int> (m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    row[i] += grid[i][j];
                    col[j] += grid[i][j]; 
                }
            }
        }
        for(int i= 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int onesRowi=row[i];
                int onesColj=col[j];
                int zerosRowi=n-row[i];
                int zerosColj=m-col[j];
                diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj;
            }
        }
        return diff;
    }
};