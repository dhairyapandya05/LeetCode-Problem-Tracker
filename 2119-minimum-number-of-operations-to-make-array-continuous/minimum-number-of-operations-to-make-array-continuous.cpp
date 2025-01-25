class Solution {
public:
    int minOperations(vector<int>& nums) {
        set<int>st (nums.begin(),nums.end());
        vector<int>temp (st.begin(),st.end());

        int n = temp.size();
        int result = INT_MAX;
        for (int i = 0; i < n; i++) {
            int L=temp[i];
            int R=L+nums.size()-1;
            auto itrJ=upper_bound(temp.begin(),temp.end(),R);
            int j=itrJ-temp.begin();
            int inrange=j-i;
            int operation=nums.size()-inrange;
            result = min(result, operation);
        }
        return result;
    }
};