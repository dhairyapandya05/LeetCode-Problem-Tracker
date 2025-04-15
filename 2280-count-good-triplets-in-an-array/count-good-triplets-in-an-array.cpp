class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> I(n);
        for (int i = 0; i < n; i++) {
            I[nums2[i]] = i;
        }
        vector<int> BIT_L(n);
        vector<int> BIT_R(n);
        for (int i = 0; i < n; i++) {
            addValue(BIT_R, i, 1);
        }
        long long res = 0;
        for (int i = 0; i < n; i++) {
            int y = nums1[i];
            int left = getRange(BIT_L, 0, I[y]);
            int right = getRange(BIT_R, I[y] + 1, n - 1);
            res += (long long)left * right;
            addValue(BIT_L, I[y], 1);
            addValue(BIT_R, I[y], -1);
        }
        return res;
    }

    int getPrefix(vector<int>& BIT, int idx) {
        int res = 0;
        while (idx >= 0) {
            res += BIT[idx];
            idx = (idx & (idx + 1)) - 1;
        }
        return res;
    }

    void addValue(vector<int>& BIT, int idx, int val) {
        while (idx < BIT.size()) {
            BIT[idx] += val;
            idx = idx | (idx + 1);
        }
    }

    int getRange(vector<int>& BIT, int l, int r) {
        if (l > r) {
            return 0;
        }
        return getPrefix(BIT, r) - (l == 0 ? 0 : getPrefix(BIT, l - 1));
    }
};