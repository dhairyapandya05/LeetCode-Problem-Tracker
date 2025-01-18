class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int j=i;
            string temp;
            while(i<n-1 and nums[i]==nums[i+1]-1){
                // j++;
                i++;
            }
            if(j==i){
                temp=to_string(nums[i]);
            }
            else{
                temp=to_string(nums[j])+"->"+to_string(nums[i]);
                j++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};