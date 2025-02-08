class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> available;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> unavailable;

        int n = servers.size();
        int m = tasks.size();
        vector<int> result(m);

        // Populate available servers in min-heap {weight, index}
        for (int i = 0; i < n; i++) {
            available.push({servers[i], i});
        }

        int time = 0;

        for (int i = 0; i < m; i++) {
            // Move time forward to at least i
            time = max(time, i);

            // If all servers are occupied, fast-forward time to the next available server
            if (available.empty()) {
                time = unavailable.top()[0];  // Move to the time when the first unavailable server becomes free
            }

            // Free up servers whose processing time has ended
            while (!unavailable.empty() && unavailable.top()[0] <= time) {
                auto temp = unavailable.top();
                unavailable.pop();
                available.push({temp[1], temp[2]});  // {weight, index}
            }

            // Assign the smallest available server
            auto tp = available.top();
            available.pop();

            int wt = tp[0];
            int idx = tp[1];

            // Assign task to server
            result[i] = idx;

            // Move server to the unavailable heap with its release time
            unavailable.push({time + tasks[i], wt, idx});
        }

        return result;
    }
};
