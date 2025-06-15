class Solution {
public:
    void dfs(int i,vector<int>& visited,vector<vector<int>>& rooms){
        visited[i]=true;
        for(auto it:rooms[i]){
            if(visited[it]==-1){
            dfs(it,visited,rooms);
            }
            
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>visited(n,-1);
        dfs(0,visited,rooms);
        return (visited==vector<int>(n,1))?true:false;
    }
};