class Solution {
public:
    int solve(int i,int amount,vector<int>&coins,vector<vector<int>>& dp){
        if(i>=coins.size() or amount<0){
            return INT_MAX;
        }
        if(amount==0) return 1;
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        int result=INT_MAX;
        for(int i=0;i<coins.size();i++){
            int temp=solve(i,amount-coins[i],coins,dp);
            if(temp!=INT_MAX){
                result=min(result,temp+1);
            }
        }
        return dp[i][amount]=result;
    }
    int coinChange(vector<int>& coins, int amount) {
        int t=coins.size();
        vector<vector<int>>dp(t,vector<int>(amount+1,-1));
        int ans=solve(0,amount,coins,dp);
        return ans==INT_MAX?-1:ans-1;
    }
};