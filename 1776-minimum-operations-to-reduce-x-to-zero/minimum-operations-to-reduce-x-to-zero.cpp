class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            mp[sum] = i;
        }
        if(sum<x) return -1;
        int target = sum - x;

        int maxans = INT_MIN;
        sum=0;
        for (int i = 0; i < n; i++) {
            sum+=nums[i];
            int tofind =  sum-target;
            if(tofind<0)continue;// this is the op
            if (mp.find(tofind) != mp.end()) {
                int temp = i - mp[tofind];
                maxans = max(maxans, temp);
            }
        }
        return (maxans==INT_MIN)?-1:(n - maxans);// to get the minimum
    }
};