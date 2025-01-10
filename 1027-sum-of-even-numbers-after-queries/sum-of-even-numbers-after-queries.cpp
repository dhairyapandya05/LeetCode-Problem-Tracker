class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int initevensum=0;
        for(auto it:nums){
            if(it%2==0) initevensum+=it;
        }
        vector<int> ans;
        for(auto q:queries){
            int value=q[0];
            int idx=q[1];
            if(nums[idx]%2==0){
                initevensum-=nums[idx];
            }
            nums[idx]+=value;
            if(nums[idx]%2==0){
                initevensum+=nums[idx];
            }
            
            ans.push_back(initevensum);
        }
        return ans;
    }
};