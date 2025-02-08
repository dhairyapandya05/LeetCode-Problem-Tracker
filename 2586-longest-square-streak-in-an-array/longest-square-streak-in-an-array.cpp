class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int maxStreak=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int root=(int)sqrt(nums[i]);
            if(root*root==nums[i] and mp.find(root)!=mp.end()){
                mp[nums[i]]=mp[root]+1;
            }
            else {
                mp[nums[i]]=1;
            }
            maxStreak=max(maxStreak,mp[nums[i]]);
        }
        return (maxStreak>=2)?maxStreak:(-1);
    }
};