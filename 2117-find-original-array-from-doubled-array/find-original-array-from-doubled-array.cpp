class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        vector<int> result;
        if (n % 2 == 1)
            return {};
        unordered_map<int, int> mp;
        for (auto& it : changed) {
            mp[it]++;
        }
        sort(changed.begin(), changed.end());
        for (int i = 0; i < n; i++) {
            int ele = changed[i];
            int target = 2 * ele;
            if (mp[ele] == 0)
                continue;
            if (mp.find(target) == mp.end() or mp[target] == 0)
                return {};
            result.push_back(ele);
            mp[ele]--;
            mp[target]--;
        }
        return result;
    }
};