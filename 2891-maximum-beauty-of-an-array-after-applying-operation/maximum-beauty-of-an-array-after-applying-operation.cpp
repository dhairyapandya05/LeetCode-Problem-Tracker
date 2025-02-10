class Solution {
public:
    int binarysearch(vector<int>& nums,int target){
        int s=0;
        int ans=0;
        int e=nums.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]>target){
                e=mid-1;
            }
            else{
                ans=mid;
                s=mid+1;
            }
        }
        return ans;

    }
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int right = 0;
        int maxBeauty = 0;

        for(int left = 0; left<nums.size(); left++){
            int x=nums[left];
            int y=x+(2*k);
           int right=binarysearch(nums,y);
  
            maxBeauty = max(maxBeauty,right-left+1);
        }
        return maxBeauty;
    }
};