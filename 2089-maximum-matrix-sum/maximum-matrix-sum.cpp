class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long neg=0;
        long long sum = 0;        
        int n = matrix.size();
        long long neg_sum = 0;
        bool zero = false;
        long long mini = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mini = min(mini, llabs(matrix[i][j]));
                if(matrix[i][j]==0){
                    zero = true;
                }
                if (matrix[i][j] < 0) {
                    neg++;
                    neg_sum += abs(matrix[i][j]);
                } 
                else {
                    sum += matrix[i][j];
                }
            }
        }

        if (neg% 2 != 0 && !zero) {
            sum = sum + neg_sum - 2LL *(mini);
        } else {
            sum += neg_sum;
        }

        return sum;
    }
};