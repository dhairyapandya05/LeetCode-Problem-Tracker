class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int moreneeded = target - nums[i];
            auto it=mp.find(moreneeded);
            if(it!=mp.end()){
                return {it->second +1,i+1};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};