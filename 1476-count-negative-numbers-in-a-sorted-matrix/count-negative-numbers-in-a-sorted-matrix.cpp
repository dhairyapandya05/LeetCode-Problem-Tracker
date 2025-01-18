class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=n-1,j=0;i>=0;i--){
            for(;j<m;j++){
                if(grid[i][j]<0){
                    cnt+=(m-j);
                    cout<<cnt<<"g ";
                    break;
                }
            }
        }
        return cnt;
    }
};