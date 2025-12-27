class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {

        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> available;
        for (int i = 0; i < n; i++) {
            available.push(i);
        }

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > busyRoom;

        vector<int> count(n, 0);

        for (auto &m : meetings) {
            long long start = m[0];
            long long end = m[1];
            long long duration = end - start;

            while (!busyRoom.empty() && busyRoom.top().first <= start) {
                available.push(busyRoom.top().second);
                busyRoom.pop();
            }

            if (!available.empty()) {
                int room = available.top();
                available.pop();
                busyRoom.push({end, room});
                count[room]++;
            } else {
                auto [freeTime, room] = busyRoom.top();
                busyRoom.pop();
                long long newEnd = freeTime + duration;
                busyRoom.push({newEnd, room});
                count[room]++;
            }
        }

        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (count[i] > count[ans]) {
                ans = i;
            }
        }

        return ans;
    }
};