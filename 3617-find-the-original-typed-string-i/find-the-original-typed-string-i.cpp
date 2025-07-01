class Solution {
public:
    int possibleStringCount(string word) {
        vector<int> repetation;
        int n = word.length();
        char lastch = word[0];
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            if (word[i] == lastch) {
                cnt++;
            } else {
                if (cnt == 0) {
                    lastch = word[i];
                    continue;
                } else {
                    repetation.push_back(cnt);
                    lastch = word[i];
                    cnt = 0;
                }
            }
        }
        if (cnt > 0) {
            repetation.push_back(cnt);
        }
        int finalans = 0;
        for (auto it : repetation) {
            finalans += it;
        }
        return finalans + 1;
    }
};