class Solution {
public:
    void dfs(int u,vector<int>& visited,unordered_map<int,vector<pair<int,int>>>& mp, int& result){
        visited[u]=true;
        for(auto it:mp[u]){
            result=min(result,it.second);
            if(!visited[it.first])
                dfs(it.first,visited,mp,result);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int>visited(n+1,false);
        unordered_map<int,vector<pair<int,int>>>adj;
        int result=INT_MAX;
        for(auto it:roads){
            int u=it[0];
            int v=it[1];
            int d=it[2];
            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }
        dfs(1,visited,adj,result);
        return result==INT_MAX?0:result;
    }
};