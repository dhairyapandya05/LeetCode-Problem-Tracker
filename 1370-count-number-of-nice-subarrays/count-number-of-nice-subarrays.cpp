class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int oddcount=0;
        int prevcount=0;
        int result=0;
        int i=0,j=0;
        while(j<n){
            if(nums[j]%2!=0){
                oddcount++;
                prevcount=0;
            }
            while(oddcount==k){
                prevcount++;
                if(nums[i]%2==1){
                    oddcount--;
                }
                i++;
            }
            result+=prevcount;
            j++;
        }
        return result;
    }
};