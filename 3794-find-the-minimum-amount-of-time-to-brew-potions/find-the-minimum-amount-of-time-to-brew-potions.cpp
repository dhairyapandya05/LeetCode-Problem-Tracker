class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<long long> pfx(n, 0), prev(n, 0);
        partial_sum(begin(skill), end(skill), begin(pfx));
        for (int i = 0; i < m; ++i) {
            long long mx = prev[0];
            for (int j = 1; j < n; ++j) mx = max(mx, prev[j] - pfx[j - 1] * mana[i]);
            for (int j = 0; j < n; ++j) prev[j] = mx + pfx[j] * mana[i];
        }
        return prev.back();
    }
};