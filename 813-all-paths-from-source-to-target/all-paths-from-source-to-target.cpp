class Solution {
public:
    void dfs(int node,vector<int>path , vector<vector<int>>& ans,vector<vector<int>>& graph){
        if(node==graph.size()-1){
            ans.push_back(path);
            path={};
            return;
        }
        for(auto it:graph[node]){
            path.push_back(it);
            dfs(it,path,ans,graph);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>tempPath;
        tempPath.push_back(0);
        dfs(0,tempPath,ans,graph);
        return ans;
    }
};