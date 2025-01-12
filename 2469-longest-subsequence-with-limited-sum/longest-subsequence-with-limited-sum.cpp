class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        vector<int>ans;
        for(int it:queries){
            auto temp=upper_bound(nums.begin(),nums.end(),it);
            int dist=distance(nums.begin(),temp);
            ans.push_back(dist);
        }
        return ans;
    }
};