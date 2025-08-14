class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        int maxInt = -1;
        int count = 1;
        int l = 0, r = 1;

        while (l < n && r < n) {
            if (num[l] == num[r]) {
                count++;
            } else {
                l = r;
                count = 1;
            }

            if (count == 3) {
                int currdigit = num[r] - '0';
                maxInt = max(maxInt, currdigit);
            }
            r++;
        }

        if (maxInt < 0) return "";
        return string(3, maxInt + '0');
    }
};