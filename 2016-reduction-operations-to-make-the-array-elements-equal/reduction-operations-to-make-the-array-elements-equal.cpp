class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int, int> mp;
        for (auto it : nums) {
            mp[it]++;
        }
        int totaloperations = 0;
        int operations=0;

        int n = mp.size();
        for (auto it = prev(mp.end()); it != mp.begin(); it--) {
            cout << (it->first) << "d ";
            operations+=it->second;
            totaloperations += operations;
        }
        return totaloperations;
    }
};