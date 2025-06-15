class Solution {
public:
    bool isSafe(int x,int y,vector<vector<char>>& maze){
        return x>=0 and x<maze.size() and y>=0 and y<maze[0].size() and maze[x][y]=='.';
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& enterance) {
        int n = maze.size();
        int m = maze[0].size();
        queue<pair<int, int>> qe;
        for (int i = 0; i < n; i++) {
            if (enterance[0] == i and enterance[1] == 0)
                continue;
            if (maze[i][0] == '.') {
                qe.push({i, 0});
                maze[i][0] = '$';
            }
        }
        for (int i = 0; i < n; i++) {
            if (enterance[0] == i and enterance[1] == m - 1)
                continue;
            if (maze[i][m - 1] == '.') {
                qe.push({i, m - 1});
                maze[i][m - 1] = '$';
            }
        }

        for (int i = 1; i < m; i++) {
            if (enterance[0] == 0 and enterance[1] == i)
                continue;
            if (maze[0][i] == '.') {
                qe.push({0, i});
                maze[0][i] = '$';
            }
        }
        for (int i = 1; i < m; i++) {
            if (enterance[0] == n - 1 and enterance[1] == i)
                continue;
            if (maze[n - 1][i] == '.') {
                qe.push({n - 1, i});
                maze[n - 1][i] = '$';
            }
        }
        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        if (qe.empty())
            return -1;
        int steps = 0;
        while (!qe.empty()) {
            int N = qe.size();
            while (N--) {
                auto fr = qe.front();
                if(fr.first==enterance[0] and fr.second==enterance[1]){
                    return steps;
                }
                qe.pop();
                for (auto it : dir) {
                    int newx = fr.first + it[0];
                    int newy = fr.second + it[1];
                    if (isSafe(newx, newy,maze)) {
                        qe.push({newx,newy});
                        maze[newx][newy] = '$';
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};