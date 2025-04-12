class Solution {
public:
    long long totalPermutations(int zeros, int nonzeros,
                               unordered_map<int, int> freq, vector<long long>& factorial) {
        int totaldigits = zeros + nonzeros;
        long long ans = nonzeros * factorial[totaldigits - 1];
        for (auto it : freq) {
            ans /= factorial[it.second];
        }
        return ans;
    }

    long long countGoodIntegers(int n, int k) {
        long long result = 0;
        unordered_set<string> st;

        vector<long long> factorial(11, 1);
        for (int i = 1; i < 11; i++) {
            factorial[i] = factorial[i - 1] * i;
        }

        int d = (n + 1) / 2;
        int start = pow(10, d - 1);
        int end = pow(10, d) - 1;

        for (int i = start; i <= end; i++) {
            string lefthalf = to_string(i);
            string righthalf = (n % 2 == 1) ? lefthalf.substr(0, d - 1) : lefthalf;
            reverse(righthalf.begin(), righthalf.end());
            string fullnumber = lefthalf + righthalf;

            long long num = stoll(fullnumber);
            if (num % k != 0)
                continue;

            string sortedFull = fullnumber;
            sort(sortedFull.begin(), sortedFull.end());
            st.insert(sortedFull);
        }

        for (const string& it : st) {
            unordered_map<int, int> mp;
            for (char ch : it) {
                mp[ch - '0']++;
            }
            int zeros = mp[0];
            result += totalPermutations(zeros, it.length() - zeros, mp, factorial);
        }

        return result;
    }
};
