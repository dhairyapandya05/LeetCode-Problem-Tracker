class Solution {
public:
    int solve(int amount, vector<int>& coins,vector<int>&dp) {
        if (amount < 0)
            return INT_MAX;
        if (amount == 0)
            return 0;
        if(dp[amount]!=-1){
            return dp[amount];
        }
        int mini = INT_MAX;
        for (int coin : coins) {
            int res = solve(amount - coin, coins,dp);
            if (res != INT_MAX)
                mini = min(mini, 1 + res);
        }
        return dp[amount]=mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int ans = solve(amount, coins,dp);
        return ans == INT_MAX ? -1 : ans;
    }
};