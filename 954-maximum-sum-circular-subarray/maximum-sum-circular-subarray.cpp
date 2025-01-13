class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            maxi = max(maxi, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return maxi;
    }

    int minSubArray(vector<int>& nums) {
        int sum = 0;
        int mini = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            mini = min(mini, sum);
            if (sum > 0) {
                sum = 0;
            }
        }
        return mini;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int maxi=maxSubArray(nums);
        int mini=minSubArray(nums);
        int sum=accumulate(nums.begin(),nums.end(),0);
        int circularsum=sum-mini;
        if(maxi>0) return max(circularsum,maxi);
        return maxi;
    }
};