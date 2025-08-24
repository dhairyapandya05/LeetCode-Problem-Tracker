class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0,j=0,n=nums.size();
        int deletion=0;
        int maxLen=0;
        while(j<n){
            if(nums[j]==0){
                deletion++;
            }
            while(deletion>1){
                if(nums[i]==0){
                    deletion--;
                }
                i++;
                
            }
            maxLen=max(maxLen,j-i);
            j++;
        }
        return maxLen;
    }
};