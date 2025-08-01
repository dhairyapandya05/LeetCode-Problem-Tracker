class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> finalans(numRows);
        for (int i = 0; i < numRows; i++) {
            finalans[i] = vector<int>(i + 1, 1);
            for (int j = 1; j < i; j++) {
                finalans[i][j] = finalans[i - 1][j] + finalans[i - 1][j - 1];
            }
        }

        return finalans;
    }
};