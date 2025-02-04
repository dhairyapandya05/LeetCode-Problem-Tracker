class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<=4) return 0;
        sort(nums.begin(),nums.end());
        int diff=INT_MAX;
        diff=min(diff,nums[n-4]-nums[0]);
        diff=min(diff,nums[n-3]-nums[1]);
        diff=min(diff,nums[n-2]-nums[2]);
        diff=min(diff,nums[n-1]-nums[3]);
        return diff;
    }
};