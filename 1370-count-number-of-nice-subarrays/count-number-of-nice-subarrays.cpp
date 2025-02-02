class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int oddcount=0,n=nums.size();

        int result=0;
        for(int i=0;i<n;i++){
            oddcount+=(nums[i]%2==1);
            if(mp.find(oddcount-k)!=mp.end()){
                result+=mp[oddcount-k];
            }
            mp[oddcount]++;
        }
        return result;
    }
};