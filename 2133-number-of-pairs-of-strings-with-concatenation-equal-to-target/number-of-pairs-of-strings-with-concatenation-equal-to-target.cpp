class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                string temp=nums[i]+nums[j];
                if(temp==target) cnt++;
            }
        }
        return cnt;
    }
};