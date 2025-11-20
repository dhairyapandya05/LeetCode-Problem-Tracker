class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {

        // 1. Sort by end point R (ascending), and by start point L (descending) as tiebreaker.
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });

        // 'chosen' will store the set S of intersection points.
        vector<int> chosen;

        for (auto &it : intervals) {
            int L = it[0], R = it[1];

            int cnt = 0;

            // 2. Count how many chosen nums lie inside current interval [L, R]
            for (int x : chosen) {
                if (x >= L && x <= R) cnt++;
            }

            // 3. Greedy Action based on Count (cnt)
            
            // If 2 already inside → continue
            if (cnt >= 2) continue;

            // If 1 inside → need 1 more (choose the largest possible point: R)
            if (cnt == 1) {
                chosen.push_back(R);
            }

            // If 0 inside → need 2 more (choose the two largest possible points: R-1 and R)
            if (cnt == 0) {
                chosen.push_back(R - 1);
                chosen.push_back(R);
            }
        }

        return chosen.size();
    }
};