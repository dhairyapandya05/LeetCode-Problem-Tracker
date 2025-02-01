class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int cumSum=0;
        int result=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            cumSum+=nums[i];
            if(mp.find(cumSum-k)!=mp.end()){
                result+=mp[cumSum-k];
            }
            mp[cumSum]++;
        }
        return result;
    }
};