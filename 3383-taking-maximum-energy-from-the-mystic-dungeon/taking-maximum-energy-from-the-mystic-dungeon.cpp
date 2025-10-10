class Solution {
public:
    int maximumEnergy(vector<int>& nums, int k) {
        //prefix sum
        /*
        calculate from back and maintain a global maxSum, so that we dont need to determine the starting value initially
        */
        int n = nums.size();int ans = INT_MIN;
        for(int i=n-k-1;i>=0;i--){
            nums[i]+=nums[i+k];
        }
        for(int i=0;i<n;i++){
            ans = max(ans,nums[i]);
        }
        return ans;
    }
};