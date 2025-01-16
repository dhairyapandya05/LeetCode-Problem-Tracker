class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();

        for(int i=1;i<n;i++) nums[i]+=nums[i-1];
        mp[0]=1;
        int cnt=0;
        for(int i=0;i<n;i++){
            int reminder=nums[i]%k;
            if(reminder<0) reminder+=k;
            if(mp.find(reminder)!=mp.end()){
                cnt+=mp[reminder];
            }
            mp[reminder]++; 
        }
        return cnt;
    }
};