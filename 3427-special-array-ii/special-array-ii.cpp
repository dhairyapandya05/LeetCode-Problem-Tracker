class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m=queries.size();
        vector<int> cumsum(n, 0);
        for(int i=1;i<n;i++){
            if(nums[i]%2==nums[i-1]%2){
                cumsum[i]=cumsum[i-1]+1;
            }
            else{
                cumsum[i]=cumsum[i-1];
            }
        }
        vector<bool>result(m,false);
        for(int i=0;i<m;i++){
            int start=queries[i][0];
            int end=queries[i][1];
            if(cumsum[end]-cumsum[start]==0){
                result[i]=true;
            }
        }
        return result;
    }
};
