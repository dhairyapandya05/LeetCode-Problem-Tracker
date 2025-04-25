class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {        
        int n = nums.size();
        long long ans = 0, sum = 0;
        unordered_map<int, long long> cnt;
        cnt[0] = 1;
        for (int i = 0; i < n; i++) {
            sum += nums[i] % modulo == k;
            ans += cnt[(sum - k + modulo) % modulo];
            cnt[sum % modulo]++;
        }
        return ans;
    }
};