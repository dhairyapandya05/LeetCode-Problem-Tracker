class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> stack;

        for (int i = 0; i <= n; i++) {
            int cur = (i < n ? nums[i] : 0); 
            while (!stack.empty() && stack.back() > cur) {
                int height = stack.back();
                stack.pop_back();
                while (!stack.empty() && stack.back() == height)
                    stack.pop_back(); 
                ans++;
            }
            if (stack.empty() || stack.back() < cur)
                stack.push_back(cur);
        }

        return ans;
    }
};