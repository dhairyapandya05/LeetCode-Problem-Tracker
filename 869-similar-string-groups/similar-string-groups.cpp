class Solution {
public:
    bool isSimilar(string s, string t){
        if(s.length()!=t.length()) return false;
        int diff=0;
        int n=t.length();
        for(int i=0;i<n;i++){
            if(s[i]!=t[i])diff++;
        }
        return diff==0 or diff==2;
    }
    void dfs(int node,vector<bool>& visited, unordered_map<int,vector<int>>& mp){
        visited[node]=true;
        for(auto it:mp[node]){
            if(!visited[it]){
                dfs(it,visited,mp);
            }
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        unordered_map<int,vector<int>>adj;
        int n=strs.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isSimilar(strs[i], strs[j])){
                    adj[j].push_back(i);
                    adj[i].push_back(j);
                }
            }
        }
        vector<bool>visited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(i,visited,adj);
            }
        }



        return count;
    }
};