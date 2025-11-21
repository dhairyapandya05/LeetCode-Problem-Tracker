class Solution {
public:
    int countPalindromicSubsequence(string s) {
        const int n = s.size();
        vector<int> first(26, -1);
        vector<int> last(26, -1);
        unordered_set<string> unique_pldr;

        for (int i = 0; i < n; i++) {
            if (first[s[i] - 'a'] == -1) 
                first[s[i] - 'a'] = i;
            
            last[s[i] - 'a'] = i;
        }

        // iterate in first and from first select every ele as mid till last. 
        for (int i = 0; i < 26; i++) {
            if (first[i] != -1) {
                for (int j = first[i] + 1; j < last[i]; j++) {
                    string str = "";
                    str.push_back(i + 'a'); // first ele
                    str.push_back(s[j]); // mid ele

                    unique_pldr.insert(str);
                }
            }
        } 

        return unique_pldr.size();
    }
};