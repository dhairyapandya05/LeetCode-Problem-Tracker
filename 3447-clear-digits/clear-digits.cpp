class Solution {
public:
    string clearDigits(string s) {
        string result = "";
        for (int i = 0; i < s.length(); i++) {
            result += s[i];
            if (isdigit(s[i])) {

                result.pop_back();
                result.pop_back();
            }
        }
        return result;
    }
};