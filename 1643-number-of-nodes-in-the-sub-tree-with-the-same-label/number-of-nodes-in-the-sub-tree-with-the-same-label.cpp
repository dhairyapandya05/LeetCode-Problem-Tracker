class Solution {
public:
    unordered_map<int,vector<int>>mp;
    vector<int> dfs(int node,int parent,unordered_map<int,vector<int>>&adj,string& labels,vector<int>& ans){
        vector<int> tempmap(26,0);
        tempmap[labels[node]-'a']++;
        for(auto it:adj[node]){
            if(it==parent) continue;
            vector<int>temp=dfs(it,node,adj,labels,ans);
            for(int i=0;i<26;i++){
                tempmap[i]+=temp[i];
            }
        }
        ans[node]=tempmap[labels[node]-'a'];
        return tempmap;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int,vector<int>>adj;
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>ans(n,0);

        auto rootmp=dfs(0,-1,adj,labels,ans);
        // mp[0]=rootmp;
        // for(int i=0;i<n;i++){
        //     auto temp_mp=mp[i];
        //     ans[i]=temp_mp[labels[i]-'a'];
        // }
        return ans;
    }
};