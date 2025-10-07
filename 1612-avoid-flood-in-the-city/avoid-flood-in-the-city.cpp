class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);
        unordered_map<int, int> full; // lake -> last day it was filled
        set<int> zeros;              // indices of zero days

        for (int i = 0; i < n; i++) {
            int lake = rains[i];
            if (lake == 0) {
                zeros.insert(i);     // add zero day
            } else {
                // if lake already full, must dry before today
                if (full.count(lake)) {
                    // find zero day after last fill
                    auto it = zeros.lower_bound(full[lake]);
                    if (it == zeros.end()) return {}; // no drying day available
                    ans[*it] = lake;     // assign this zero day to dry lake
                    zeros.erase(it);
                }
                ans[i] = -1; // rain day
                full[lake] = i;
            }
        }
        return ans;
    }
};