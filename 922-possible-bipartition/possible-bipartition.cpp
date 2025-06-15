class Solution {
public:
    bool bfs(unordered_map<int, vector<int>>& mp, int i,vector<int>& color ) {
        queue<int> qe;
        qe.push(i);
        color[i]=1;
        while (!qe.empty()) {
            int N = qe.size();
            while (N--) {
                int fr=qe.front();
                qe.pop();
                for(auto v:mp[fr]){
                    if(color[v]==color[fr]){
                        return false;
                    }
                    if(color[v]==-1){
                        qe.push(v);
                        color[v]=1-color[fr];
                    }
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> mp;
        for (auto it : dislikes) {
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        vector<int> color(n + 1, -1);
        for (int i = 1; i < n + 1; i++) {
            if (color[i] == -1) {
                if (!bfs(mp, i, color)) {
                    return false;
                }
            }
        }
        return true;
    }
};