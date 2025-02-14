class Solution {
public:
    int getSumDigits(int num){
        int sum=0;
        while(num){
            sum+=num%10;
            num/=10;
        }
        return sum;

    }
    int maximumSum(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int sumDigits = getSumDigits(nums[i]);
            if (mp.find(sumDigits) != mp.end()) {
                ans=max(mp[sumDigits]+nums[i],ans);
                mp[sumDigits] = max(mp[sumDigits], nums[i]);
            }
            else{
                mp[sumDigits] =nums[i];
            }
            
        }
        return ans;
    }
};