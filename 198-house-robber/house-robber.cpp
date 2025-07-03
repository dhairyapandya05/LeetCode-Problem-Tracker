class Solution {
public:
    int solve(int i, vector<int>& nums,vector<int>&dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        // take 
        int take=0,nottake=0;
        take=nums[i]+solve(i+2,nums,dp);
        //not take

        nottake=solve(i+1,nums,dp);
        return dp[i]=max(take,nottake);

    }
    int rob(vector<int>& nums) {
        int indx=0;
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(indx,nums,dp);
    }
};