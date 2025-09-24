class Solution {
public:
    string getFractionPart(long long n, long long d) {
        // map of seen remainders
        map<int, int> rem_map;
        string frac;
        while (n) {
            if (rem_map.count(n)) {
                // the reptend occurs when the same remainder appears multiple times
                int pos = rem_map[n];
                frac.insert(frac.begin() + pos, '(');
                frac += ')';
                break;
            }
            rem_map[n] = (int) frac.size();
            frac += to_string(n / d);
            n = (n % d) * 10;
        }
        return frac;
    }

    string fractionToDecimal(int nn, int dd) {
        bool is_neg = (nn < 0 && dd > 0) || (nn > 0 && dd < 0);
        long long n = nn, d = dd;
        n = abs(n), d = abs(d);
        string decimal;
        if (is_neg) decimal += '-';
        long long whole = n / d;
        n %= d;
        decimal += to_string(whole);
        if (n != 0) decimal += '.' + getFractionPart(10 * n, d);
        return decimal;
    }
};