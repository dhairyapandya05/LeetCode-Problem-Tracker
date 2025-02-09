class Solution {
public:
    void solve(vector<int>& nums,vector<int>& dp,int& n){
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[j]+1,dp[i]);
                }
            }
        }
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int> increasing(n,1);
        vector<int> decreasing(n,1);
        solve(nums,increasing,n);
        reverse(nums.begin(),nums.end());
        solve(nums,decreasing,n);
        reverse(decreasing.begin(),decreasing.end());
        int mountainlength=0;
        for(int i=0;i<n;i++){
            if(increasing[i]==1 or decreasing[i]==1){
                continue;
            }
            mountainlength=max(mountainlength,increasing[i]+decreasing[i]-1);
        }
        int removal=n-mountainlength;
        return removal;
    }
};