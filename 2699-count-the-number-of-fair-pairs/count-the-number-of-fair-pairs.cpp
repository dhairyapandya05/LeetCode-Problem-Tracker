class Solution {
public:
    int lowerBinarySearch(int i,int e,int& iNum,vector<int>&nums,int& lower){
        int s=i+1;
        int ans=i;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(iNum+nums[mid]>=lower){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }

    int upperBinarySearch(int i,int e,int& iNum,vector<int>&nums,int& upper){
        int s=i+1;
        int ans=i;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(iNum+nums[mid]<=upper){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long int ans=0;
        for(int i=0;i<n-1;i++){
            int iNum=nums[i];
            int loweridx=lowerBinarySearch(i,n-1,iNum,nums,lower);
            int upperidx=upperBinarySearch(i,n-1,iNum,nums,upper);
            if(upperidx!=i and loweridx!=i and upperidx>=loweridx){
                ans+=(upperidx-loweridx+1);
            }
        }
        return ans;
    }
};