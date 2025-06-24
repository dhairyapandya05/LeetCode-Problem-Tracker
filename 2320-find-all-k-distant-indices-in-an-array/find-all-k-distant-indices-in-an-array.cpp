class Solution {
public:
    void insertIndexes(int idx, int& n, set<int>& ansSet, int k) {
        for (int i = max(0, idx - k); i <= min(n - 1, idx + k); i++) {
            ansSet.insert(i);
        }
    }
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> ansSet;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {
                insertIndexes(i, n, ansSet, k);
            }
        }
        vector<int> ans(ansSet.begin(),ansSet.end());
        return ans;
    }
};