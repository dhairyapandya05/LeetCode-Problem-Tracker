class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int oddCount=0,ans=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(auto it:nums){
            oddCount+=(it%2);
            ans+=mp[oddCount-k];
            mp[oddCount]++;

        }
        return ans;
    }
};