class Solution {
public:
    int numTeams(vector<int>& nums) {
        int teams=0;
        int n=nums.size();
        for(int i=1;i<n-1;i++){
            int leftgreater=0;
            int leftsmaller=0;
            int rightgreater=0;
            int rightsmaller=0;
            for(int k=0;k<i;k++){
                if(nums[k]>nums[i])leftgreater++;
                if(nums[k]<nums[i])leftsmaller++;
            }
            for(int k=i+1;k<n;k++){
                if(nums[k]>nums[i])rightgreater++;
                if(nums[k]<nums[i])rightsmaller++;
            }
            teams+=(leftgreater*rightsmaller)+(rightgreater*leftsmaller);
        }
        return teams;
    }
};