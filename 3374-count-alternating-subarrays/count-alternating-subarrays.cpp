class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        long long result=0;
        for(i=0;i<n;i++){
            int j=i;
            while(j+1<n and nums[j+1]!=nums[j]){
                j++;
            }
            int length=j-i+1;
            result+=((long long)length*(length+1))>>1;
            i=j;

        }
        return result;
    }
};