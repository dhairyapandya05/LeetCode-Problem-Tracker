class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<int, long long> right, left;
        long long ans = 0;

        // Count all elements in right map
        for (int x : nums) {
            right[x]++;
        }

        for (int j = 0; j < nums.size(); j++) {
            int val = nums[j];
            right[val]--; // current j is no longer on the right side

            int target = val * 2;

            long long countLeft = left[target];
            long long countRight = right[target];

            ans = (ans + countLeft * countRight) % MOD;

            left[val]++; // add current value to left map
        }

        return (int)ans;
    }
};