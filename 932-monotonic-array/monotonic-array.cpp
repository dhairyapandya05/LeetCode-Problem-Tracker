class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int increasing=false,decreasing=false;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                increasing=true;
            }
            if(nums[i]>nums[i+1]){
                decreasing=true;
            }
        }
        return (increasing ==true and decreasing==true)? false:true;
    }
};