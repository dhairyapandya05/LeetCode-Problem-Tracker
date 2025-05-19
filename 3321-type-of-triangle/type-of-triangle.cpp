class Solution {
public:
    string triangleType(vector<int>& nums) {
        if(nums[0]+nums[1]<=nums[2] or nums[1]+nums[2]<=nums[0] or nums[2]+nums[0]<=nums[1]){
            return "none";
        }
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        if(mp.size()==3) return "scalene";
        if(mp.size()==2) return "isosceles";
        return "equilateral";
    }
};