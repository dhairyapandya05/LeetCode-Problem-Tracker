class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        if (n < 2)
            return values[0] + values[1] + 0 - 1;
        vector<int> prefixMax(n);
        prefixMax[0] = values[0];
        for (int i =1; i <n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], values[i] + i);
        }
        int maxScore = INT_MIN;
        for (int i = 1; i < n; i++) {
            maxScore = max(maxScore, prefixMax[i - 1] + values[i] - i);
        }

        return maxScore;
    }
};