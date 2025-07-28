class Solution {
public:
    int solve(int idx,vector<int>& nums,int& ORtarget,int currOR){
        if(idx==nums.size()){
            return (ORtarget==currOR)?1:0;
        }
        int skip=solve(idx+1,nums,ORtarget,currOR);
        int take=solve(idx+1,nums,ORtarget,currOR | nums[idx]);

        return take+skip;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int targetOR=0;
        for(auto it:nums){
            targetOR |= it;
        }
        int currXor=0;
        int ans=solve(0,nums,targetOR,currXor);
        return ans;
    }
};