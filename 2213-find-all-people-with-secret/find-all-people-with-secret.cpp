class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        std::unordered_map<int, std::vector<std::pair<int, int>>> graph;
        for (auto& meeting : meetings) {
            int u = meeting[0], v = meeting[1], t = meeting[2];
            graph[v].emplace_back(t, u);
            graph[u].emplace_back(t, v);
        }
        for (auto& p : graph) std::sort(p.second.begin(), p.second.end());
        std::vector<int> secretAt(n, INT_MAX);
        secretAt[0] = 0;
        secretAt[firstPerson] = 0;
        std::queue<std::pair<int, int>> q;
        q.emplace(0, 0);
        q.emplace(firstPerson, 0);
        while (!q.empty()) {
            auto [person, known] = q.front();
            q.pop();
            for (auto [meetingTime, nextPerson] : graph[person]) {
                if (known <= meetingTime && meetingTime < secretAt[nextPerson]) {
                    secretAt[nextPerson] = meetingTime;
                    q.emplace(nextPerson, meetingTime);
                }
            }
        }
        std::vector<int> output;
        for (int i = 0; i < n; ++i) {
            if (secretAt[i] != INT_MAX) output.push_back(i);
        }
        return output;
    }
};