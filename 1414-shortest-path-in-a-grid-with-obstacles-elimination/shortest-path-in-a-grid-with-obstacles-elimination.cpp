class Solution {
public:
    vector<vector<int>> dir{{-1,0},{1,0},{0,1},{0,-1}};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        queue<vector<int>> qe;
        int steps=0;
        bool visited[41][41][16001];
        memset(visited,false,sizeof(visited));
        
        qe.push({0,0,k});
        visited[0][0][k]=true;
        while(!qe.empty()){
            int sz=qe.size();
            while(sz--){
                auto tp=qe.front();
                qe.pop();
                int curr_i=tp[0];
                int curr_j=tp[1];
                int obst=tp[2];
                if(curr_i==n-1 and curr_j==m-1) return steps;
                for(auto d:dir){
                    int newx=curr_i+d[0];
                    int newy=curr_j+d[1];
                    if(newx<0 or newy<0 or newx>=n or newy>=m) continue;
                    if(grid[newx][newy]==0 and visited[newx][newy][obst]==false ){
                        visited[newx][newy][obst]=true;
                        qe.push({newx,newy,obst});
                    }
                    else if(grid[newx][newy]==1 and obst>0 and visited[newx][newy][obst-1]==false){
                        visited[newx][newy][obst-1]=true;
                        qe.push({newx,newy,obst-1});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};