class Solution {
public:
    int dfs(int currNode,int parentNode,unordered_map<int,vector<int>>& mp,vector<bool>& hasApple){
        int time=0;
        
        for(auto it:mp[currNode]){
            if(it==parentNode) continue;
            time+=dfs(it,currNode,mp,hasApple);
        }
        if((hasApple[currNode] or time!=0) and currNode!=0){
            time+=2;
            cout<<"CurrNode: "<<currNode<<"Time: "<<time;
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int,vector<int>>mp;
        for(auto it:edges){
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        return dfs(0,-1,mp,hasApple);
    }
};