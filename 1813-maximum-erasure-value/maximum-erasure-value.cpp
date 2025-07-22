class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int>st;
        unordered_map<int,int>mp;
        int i=0,j=0,n=nums.size();
        int sum=0;
        int finalSum=0;
        while(j<n){
            st.insert(nums[j]);
            mp[nums[j]]++;
            sum+=nums[j];
            while(i<=j and j<n and j-i+1>st.size()){
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    st.erase(nums[i]);
                }
                sum-=nums[i];
                i++;
            }
            j++;
            finalSum=max(finalSum,sum);
        }
        return finalSum;
    }
};