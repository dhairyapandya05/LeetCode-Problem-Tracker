class Solution {
public:
    void constructLPS(vector<int>& LPS, string& pat) {
        LPS[0] = 0;
        int length = 0;
        int i = 1;
        int m = pat.length();
        while (i < m) {
            if (pat[i] == pat[length]) {
                length++;
                LPS[i] = length;
                i++;
            } else {
                if (length != 0)
                    length = LPS[length - 1];
                else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }
    }
    vector<int> search(string& pat, string& txt) {
        // code here
        int i = 0, j = 0;
        int n = txt.length();
        int m = pat.length();
        vector<int> result;
        vector<int> LPS(m, 0);
        constructLPS(LPS, pat);
        while (i < n) {
            if (txt[i] == pat[j]) {
                i++;
                j++;
            }
            if (j == m) {
                result.push_back(i - j + 1);
                j = LPS[j - 1];
            } else if (i < n and txt[i] != pat[j]) {
                if (j != 0) {
                    j = LPS[j - 1];
                } else {
                    i++;
                }
            }
        }
        return result;
    }

    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        int m = pattern.size();

        string pat = "";
        for (int i = 0; i < m; i++) {
            if (pattern[i] == -1) {
                pat += 'x';  // Use 'x' for -1
            } else {
                pat += to_string(pattern[i]);
            }
        }

        string stake = "";
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] > nums[i]) {
                stake += '1';
            } else if (nums[i + 1] == nums[i]) {
                stake += '0';
            } else {
                stake += 'x';  // Use 'x' for -1
            }
        }

        vector<int> temp = search(pat, stake);
        return temp.size();
    }
};