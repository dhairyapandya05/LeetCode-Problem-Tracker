class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> unique;
        int n = nums.size();
        unique.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1])
                unique.push_back(nums[i]);
        }
        int ans = 0;
        for (int i = 1; i < unique.size() - 1; i++) {
            if (unique[i - 1] < unique[i] && unique[i] > unique[i + 1]) {
                ans++;
            } else if (unique[i - 1] > unique[i] && unique[i] < unique[i + 1]) {
                ans++;
            }
        }
        return ans;
    }
};