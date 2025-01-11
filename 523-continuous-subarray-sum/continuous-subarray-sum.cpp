class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=-1;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int modulo=sum%k;
            if(mp.find(modulo)!=mp.end()){
                if((i-mp[modulo])>=2) return true;
            }
            else{
                mp[modulo]=i;
            
            }
        }
        return false;
    }
};