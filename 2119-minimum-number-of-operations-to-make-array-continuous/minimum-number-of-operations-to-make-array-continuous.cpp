class Solution {
public:
    int minOperations(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        vector<int> temp(st.begin(), st.end());

        int n = temp.size();
        int m = nums.size();

        int result = INT_MAX;

        for (int i = 0, j = 0; i < n; i++) {
            while (j < n && temp[j] - temp[i] < nums.size()) j++;
            result = min(result, m - (j - i));
        }
        return result;
    }
};
