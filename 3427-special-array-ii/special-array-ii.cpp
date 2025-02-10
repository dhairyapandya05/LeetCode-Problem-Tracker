class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);

        // Build prefix sum array to mark invalid indices
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + (nums[i] % 2 == nums[i - 1] % 2);
        }

        vector<bool> result;
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            result.push_back(prefix[r] == prefix[l]);
        }
        return result;
    }
};
