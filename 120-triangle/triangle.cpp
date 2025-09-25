class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {

        for (int i = static_cast<int>(triangle.size()) - 2; i >= 0; i--) {
            for (int j = 0; j < static_cast<int>(triangle[i].size()); j++) {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        
        return triangle[0][0];
    }
};