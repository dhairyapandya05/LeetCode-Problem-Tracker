//A k-mirror number is a positive integer without leading zeros that reads the same both forward and backward in base-10 as well as in base-k.
// For example, 9 is a 2-mirror number. The representation of 9 in base-10 and base-2 are 9 and 1001 respectively, which read the same both forward and backward.
// On the contrary, 4 is not a 2-mirror number. The representation of 4 in base-2 is 100, which does not read the same both forward and backward.
// Given the base k and the number n, return the sum of the n smallest k-mirror numbers.

class Solution {
public:
    long long kMirror(int k, int n) {
        auto isPalindrome = [&](long long x) -> bool {
            int liz = -1;
            while (x) { ++liz;
                digit[liz] = x % k;
                x /= k; }
            for (int i = 0, j = liz; i < j; ++i, --j) {
                if (digit[i] != digit[j]) {
                    return false; }
            }
            return true;
        };
        int lf = 1, count = 0;
        long long result = 0;
        while (count < n) {
            int rf = lf * 10;
            for (int op = 0; op < 2; ++op) {
                for (int i = lf; i < rf && count < n; ++i) {
                    long long combined = i;
                    int zv = (op == 0 ? i / 10 : i);
                    while (zv) {
                        combined = combined * 10 + zv % 10;
                        zv /= 10; }
                    if (isPalindrome(combined)) { ++count;
                        result += combined; }
                }
            } 
            lf = rf;
        }
        return result;
    }
private:
    int digit[100];
};