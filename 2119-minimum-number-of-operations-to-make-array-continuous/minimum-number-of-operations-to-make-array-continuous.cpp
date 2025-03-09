class Solution {
public:
    int minOperations(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        vector<int> temp(st.begin(), st.end());

        int m = nums.size();
        int n = temp.size();
        int result = INT_MAX;
        
        for (int i = 0, j = 0; i < n; i++) {
            while (j < n && temp[j] - temp[i] < m) j++;
            result = min(result, m - (j - i)); // Fix: use `m - (j - i)`
        }
        
        return result;
    }
};
