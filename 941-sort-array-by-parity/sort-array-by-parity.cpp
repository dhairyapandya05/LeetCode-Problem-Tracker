class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, n = nums.size(), j = 0;
        // vector<int>temp (n);

        while (i < n) {
            if (nums[i] % 2 == 0) {
                swap(nums[i], nums[j]);
                j++;
            }
            i++;
        }
        return nums;
    }
};