class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
       vector<int> indegree(n,0);
        vector<int> adj[n];
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        vector<vector<int>> dp(n,vector<int>(26,0));
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0) q.push(i);
            dp[i][colors[i]-'a']=1;
        }
        vector<int> topo;
        while(!q.empty()){
            int nodes = q.front();
            q.pop();
            topo.push_back(nodes);
            for(auto it: adj[nodes]){
                for(int c=0;c<26; c++){
                    int cnt = (colors[it]-'a' == c)?1:0;
                    dp[it][c] = max(dp[it][c],dp[nodes][c]+cnt);
                }
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(topo.size()<n) return -1;
        int result = 0;
        for(int i=0; i<n;i++){
            for(int c=0; c<26; c++){
                result = max(result,dp[i][c]);
            }
        }
        return result;
    }
};