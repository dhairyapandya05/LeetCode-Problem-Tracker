class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans(n,-1);
        if(((2*k)+1)>n) return ans;
        int i=k;
        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];

        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        for(int i=k;i<=n-k-1;i++){
            long long int leftlimit=(i-k-1>=0)?prefix[i-k-1]:0;
            long long int sum=prefix[i+k]-leftlimit;
            ans[i]=sum/((2*k)+1);
        }
        return ans;
    }
};