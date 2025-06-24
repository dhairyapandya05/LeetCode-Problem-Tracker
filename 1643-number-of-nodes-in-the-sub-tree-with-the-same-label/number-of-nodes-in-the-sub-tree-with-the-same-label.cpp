class Solution {
public:
    vector<int>GlobalHash;
    void dfs(int node,int parent,unordered_map<int,vector<int>>&adj,string& labels,vector<int>& ans){
        int before=GlobalHash[labels[node]-'a'];
        GlobalHash[labels[node]-'a']++;
        for(auto it:adj[node]){
            if(it==parent) continue;
            dfs(it,node,adj,labels,ans);
        }
        int after=GlobalHash[labels[node]-'a'];
        ans[node]=after-before;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        GlobalHash.resize(26,0);
        unordered_map<int,vector<int>> adj;
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>ans(n,0);

        dfs(0,-1,adj,labels,ans);
        
        return ans;
    }
};