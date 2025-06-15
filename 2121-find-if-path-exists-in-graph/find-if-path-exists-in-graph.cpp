class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>mp;
        for(auto it:edges){
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        vector<int> visited(n,-1);
        visited[source]=1;
        queue<int>qe;
        qe.push(source);
        while(!qe.empty()){
            int N=qe.size();
            while(N--){
                int fr=qe.front();
                qe.pop();
                if(fr==destination)
                    return true;
                
                for(auto it:mp[fr]){
                    if(visited[it]==-1){
                        visited[it]=1;
                        qe.push(it);
                    }
                }
            }
        }
        return false;
    }
};