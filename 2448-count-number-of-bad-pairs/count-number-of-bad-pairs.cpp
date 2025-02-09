class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        long long int count = 0;
        for (int i = 0; i < n; i++)
            nums[i] = nums[i] - i;
        for (int i = 0; i < n; i++) {
            if (mp.find(nums[i]) != mp.end()) {
                count += (i - mp[nums[i]]);
            } else {
                count += i;
            }
            mp[nums[i]]++;
        }
        return count;
    }
};