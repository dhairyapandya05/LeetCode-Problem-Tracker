class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int ans = 0;
        for (auto& point1 : points) {
            int x1 = point1[0], y1 = point1[1];
            for (auto& point2 : points) {
                int x2 = point2[0], y2 = point2[1];
                if (x1 == x2 && y1 == y2) continue;
                if (x1 > x2 || y1 < y2) continue;
                bool correct = true;
                for (auto& point : points) {
                    int x = point[0], y = point[1];
                    if (x == x1 && y == y1) continue;
                    if (x == x2 && y == y2) continue;
                    if (x >= x1 && x <= x2 && y <= y1 && y >= y2) {
                        correct = false;
                        break;
                    }
                }
                if (correct) {
                    ans++;
                }
            }
        }
        return ans;
    }
};