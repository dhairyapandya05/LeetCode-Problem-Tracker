class Solution {
public:
    void dfs(int node,int parent,int& count,unordered_map<int,vector<pair<int,int>>>& mp){
        for(auto it:mp[node]){
            if(it.first==parent) continue;
            count+=it.second;
            dfs(it.first,node,count,mp);
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<pair<int,int>>>mp;
        for(auto it:connections){
            mp[it[0]].push_back({it[1],1});
            mp[it[1]].push_back({it[0],0});
        }
        int count=0;
        dfs(0,-1,count,mp);

        return count;
    }
};