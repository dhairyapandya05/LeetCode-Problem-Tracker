class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        int s = 0, e = 0;
        long long int sum = 0, n = nums.size();
        while (e < n) {
            sum += nums[e];
            while (sum * (e - s + 1) >= k) {
                sum -= nums[s];
                s++;
            }
            ans+=(e-s+1);
            e++;
        }

        return ans;
    }
};