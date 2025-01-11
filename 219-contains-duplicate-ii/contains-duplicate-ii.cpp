class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int num=nums[i];
            if(mp.find(num)==mp.end()){
            }
            else{
                if(i-mp[num]<=k) return true;
            }
                mp[num]=i;
        }
        return false;
    }
};