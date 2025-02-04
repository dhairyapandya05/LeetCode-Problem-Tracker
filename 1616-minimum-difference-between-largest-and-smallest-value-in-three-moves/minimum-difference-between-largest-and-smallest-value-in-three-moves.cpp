class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<=4) return 0;
        partial_sort(nums.begin(),nums.begin()+4,nums.end()); //n*log(4)
        nth_element(nums.begin()+4,nums.begin()+(n-4),nums.end()); //n*log(4) it implements partisiioning technique so tbe time compleity is O(n)
        sort((nums.begin()+n-4),nums.end());
        int diff=INT_MAX;
        diff=min(diff,nums[n-4]-nums[0]);
        diff=min(diff,nums[n-3]-nums[1]);
        diff=min(diff,nums[n-2]-nums[2]);
        diff=min(diff,nums[n-1]-nums[3]);
        return diff;
    }
};