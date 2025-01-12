class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long int leftsum=0;
        int n=nums.size();
        long long int totalsum=accumulate(nums.begin(),nums.end(),0LL);
        long long int mini=INT_MAX;
        long long int rightsum=0;
        int miniidx=-1;
        for(int i=0;i<n-1;i++){
            leftsum+=nums[i];
            rightsum=totalsum-leftsum;
            long long int temp=abs(leftsum/(i+1) - (rightsum/(n-i-1)));
            if(temp<mini){
                mini=temp;
                miniidx=i;
            }
        }
        if(mini>(totalsum/n)){
            return n-1;
        }
        return miniidx;
    }
};