class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(n);
        vector<int>prefixSum(n);
        prefixSum[0]=nums[0];
        for(int i=1;i<n;i++){
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }
        for(int i=0;i<n;i++){
            int leftsum=prefixSum[i]-nums[i];
            int rightsum=prefixSum[n-1]-prefixSum[i];
            result[i]=(nums[i]*i)-leftsum+rightsum-(nums[i]*(n-i-1));

        }
        return result;
    }
};