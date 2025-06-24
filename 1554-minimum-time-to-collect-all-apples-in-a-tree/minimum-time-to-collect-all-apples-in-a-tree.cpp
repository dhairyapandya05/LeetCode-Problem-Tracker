class Solution {
public:
    int dfs(int currNode, int parentNode, unordered_map<int, vector<int>>& mp,
            vector<bool>& hasApple) {
        int time = 0;

        for (auto it : mp[currNode]) {
            if (it == parentNode)
                continue;
            int timefromchild =dfs(it, currNode, mp, hasApple);
            if ((hasApple[it] or timefromchild != 0)) {
                time+=(timefromchild + 2);
            }
        }

        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, vector<int>> mp;
        for (auto it : edges) {
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        return dfs(0, -1, mp, hasApple);
    }
};