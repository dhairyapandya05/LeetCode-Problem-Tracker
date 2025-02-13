class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();

        long long firstRowRemainingSum=accumulate(grid[0].begin(),grid[0].end(),0LL);
        long long secondRowRemainingSum=0;
        long long minimisedRow2Sum=LONG_LONG_MAX;
        for(int RobCol=0;RobCol<n;RobCol++){
            firstRowRemainingSum-=grid[0][RobCol];
            long long bestofRobot2=max(firstRowRemainingSum,secondRowRemainingSum);
            minimisedRow2Sum=min(minimisedRow2Sum,bestofRobot2);
            secondRowRemainingSum+=grid[1][RobCol];
        }
        return minimisedRow2Sum;
    }
};