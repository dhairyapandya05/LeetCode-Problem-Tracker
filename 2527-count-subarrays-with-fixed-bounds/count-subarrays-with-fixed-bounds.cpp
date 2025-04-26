class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int minPos=-1;
        int maxPos=-1;
        int criticalpos=-1;
        int l=0,r=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<minK or nums[i]>maxK){
                criticalpos=i;
            }
            if(nums[i]==minK){
                minPos=i;
            }
            if(nums[i]==maxK){
                maxPos=i;
            }
            long long int smaller=min(maxPos,minPos);
            long long int temp=smaller-criticalpos;
            ans+=(temp>0)?temp:0;
        }
        return ans;
    }
};