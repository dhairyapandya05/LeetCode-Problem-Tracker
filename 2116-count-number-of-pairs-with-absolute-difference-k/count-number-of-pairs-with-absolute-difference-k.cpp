class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>hash(101,0);
        for(auto it:nums){
            hash[it]++;
        }
        int cnt=0;
        for(int i=k+1;i<101;i++){
            cnt+=(hash[i]*hash[i-k]);
        }
        return cnt;
    }
};