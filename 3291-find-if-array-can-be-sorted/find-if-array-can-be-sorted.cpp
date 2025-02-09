class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        int prevLarget = nums[0];
        int prevsmaller = nums[0];
        int i = 1;
        for (; i < n; i++) {
            if (__builtin_popcount(nums[i]) ==
                __builtin_popcount(nums[i - 1])) {
                prevsmaller = min(prevsmaller, nums[i]);
                prevLarget = max(prevLarget, nums[i]);
            } else {
                break;
            }
        }
        
        int currsmaller =(i<n)?nums[i]:INT_MAX;
        int currlarger =(i<n)? nums[i]:INT_MIN;
        i++;
        for (; i < n; i++) {
            if (__builtin_popcount(nums[i]) ==
                __builtin_popcount(nums[i - 1])) {
                currsmaller = min(currsmaller, nums[i]);
                currlarger = max(currlarger, nums[i]);
            } else {
                if(currsmaller<prevLarget){
                    return false;
                }
                prevLarget=currlarger;
                prevsmaller=currsmaller;
                currsmaller = nums[i];
                currlarger = nums[i];
            }
        }
        return (currsmaller>prevLarget)?true:false;
    }
};