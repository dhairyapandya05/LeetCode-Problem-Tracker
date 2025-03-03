class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int i = 0, j = n - 1;
        int i_ = 0, j_ = n - 1;

        vector<int> ans(n, pivot);
        while (i_ < n and j_ >= 0) {
            if (nums[i_] < pivot) {
                ans[i] = nums[i_];
                i++;
            }
            if (nums[j_] > pivot) {
                ans[j] = nums[j_];
                j--;
            }
            i_++;
            j_--;
        }

        return ans;
    }
};