class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());  // Step 1: Sort the array
        int count = 1;                   // At least one subsequence
        int minValue = nums[0];          // Start with first element

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] - minValue > k) {
                // Difference exceeds k → new group
                count++;
                minValue = nums[i];  // Reset min for new group
            }
        }

        return count;
    }
};