class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(n);
        int sum=accumulate(nums.begin(),nums.end(),0);
        int prefixSum=0;
        for(int i=0;i<n;i++){
            int leftsum=prefixSum;
            int rightsum=sum-prefixSum-nums[i];
            result[i]=(nums[i]*i)-leftsum+rightsum-(nums[i]*(n-i-1));
            prefixSum+=nums[i];
        }
        return result;
    }
};