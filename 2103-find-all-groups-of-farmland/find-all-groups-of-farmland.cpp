class Solution {
public:
    bool isSafe(int i,int j,int& n, int& m,vector<vector<int>>&land){
        return i>=0 and j>=0 and i<n and j<m and land[i][j]==1;
    }
    vector<pair<int,int>>dir={{-1,0},{0,-1},{0,1},{1,0}};
    void dfs(int i,int j,int& n,int& m,int& maxX,int& maxY,vector<vector<int>>& land){
        maxX=max(maxX,i);
        maxY=max(maxY,j);
        land[i][j]=-1; //marking them as visited;
        for(auto& d:dir){
            if(isSafe(i+d.first,j+d.second,n,m,land))
                dfs(i+d.first,j+d.second,n,m,maxX,maxY,land);
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size();
        int m=land[0].size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j]==1){
                    int maxX=i;
                    int maxY=j;

                    dfs(i,j,n,m,maxX,maxY,land);
                    ans.push_back({i,j,maxX,maxY});
                }
            }
        }
        return ans;
    }
};