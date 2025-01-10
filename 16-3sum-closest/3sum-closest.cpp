class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans=1000000;
        for (int i = 0; i < n - 2; i++) {
            int s = i + 1, e = n - 1;
            while (s < e) {
                int sum=nums[i]+nums[s]+nums[e];
                
                if(abs(target-sum) < abs(target-ans)) {
                    ans = sum;
                }
                
                if(sum > target)
                    e--;
                else
                    s++;
            }
            // while (i + 1 < n && nums[i] == nums[i + 1])
            //     i++;
        }
        return ans;
    }
};