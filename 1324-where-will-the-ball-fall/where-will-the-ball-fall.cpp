class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid[0].size();
        int n=grid.size();
        vector<int>result;
        for(int ball=0;ball<m;ball++){
            int row=0,col=ball;
            bool atka=false;
            while(row<n and col<m){
                if(grid[row][col]==-1){
                    if(col==0 or grid[row][col-1]==1){
                        atka=true;
                        break;
                    }
                    col--;
                }
                else if(grid[row][col]==1){
                    if(col==m-1 or grid[row][col+1]==-1){
                        atka=true;
                        break;
                    }
                    col++;
                }
                row++;
            }
            if(atka==false)
            result.push_back(col);
            else{
            result.push_back(-1);                
            }
        }
        return result;
    }
};