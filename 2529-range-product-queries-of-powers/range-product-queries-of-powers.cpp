class Solution {
public:
    const int MOD = 1e9 + 7;
    void buildsegT(int i, int l, int r, vector<int>& segTr, vector<int>& power) {
        if (l == r) {
            segTr[i] = power[l]%MOD;
            return;
        }
        int mid = l + (r - l) / 2;
        buildsegT(2 * i + 1, l, mid, segTr, power);
        buildsegT(2 * i + 2, mid + 1, r, segTr, power);
        segTr[i] = (1LL * segTr[2 * i + 1] * segTr[2 * i + 2])%MOD;
    }
    int Query(int start, int end, int i, int l, int r, vector<int>& segTr) {
        if (l > end || r < start)
            return 1;
        if (l >= start && r <= end)
            return segTr[i];
        int mid = l + (r - l) / 2;
        return (1LL * Query(start, end, 2 * i + 1, l, mid, segTr) *
                Query(start, end, 2 * i + 2, mid + 1, r, segTr) % MOD);
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> power;
        int powe = 1;
        while (n > 0) {
            if (n & 1) {
                power.push_back(powe);
            }
            powe <<= 1;
            n >>= 1;
        }
        sort(power.begin(), power.end());
        int t = power.size();
        vector<int> segTr(4 * t);
        buildsegT(0, 0, t - 1, segTr, power);
        vector<int> res;
        for (int i = 0; i < queries.size(); i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            res.push_back(Query(start, end, 0, 0, t - 1, segTr));
        }
        return res;
    }
};