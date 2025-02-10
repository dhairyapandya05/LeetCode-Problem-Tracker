class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> validRightMostIdx(n,0);
        int m=queries.size();
        int i=0,j=0;
        while(i<n){
            if(j<i){    // safety cheque
                j=i;
            }
            while(j+1<n and nums[j]%2!=nums[j+1]%2){
                j++;
            }
            validRightMostIdx[i]=j; 
            i++;
        }
        vector<bool>result(m,false);
        for(int i=0;i<m;i++){
            int start=queries[i][0];
            int end=queries[i][1];
            if(end<=validRightMostIdx[start]){
                result[i]=true;
            }
        }
        return result;
    }
};
