class Solution {
public:
    void dfs(vector<vector<int>>& stones,int i,vector<int>& visited) {
        if(i>=stones.size()){
            return;
        }
        for(int j=0;j<stones.size();j++){
            if(i==j) continue;
            if(visited[j]==-1 and (stones[i][0]==stones[j][0] or stones[i][1]==stones[j][1])){
                visited[j]=1;// marking it as visted
                dfs(stones,j,visited);                
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int gangs = 0;
        vector<int> visited(n, -1);
        for (int i = 0; i < stones.size(); i++) {
            if (visited[i] == -1) {
                gangs++;
                visited[i]=1;
                dfs(stones,i,visited);
            }
        }
        cout<<"Gangs: "<<gangs;
        return n - gangs;
    }
};