class Solution {
public:

    typedef long long ll;

    long long maximumTotalDamage(vector<int>& power) {

        int n = power.size();
        vector<ll> dp(n, 0);
   
        sort(power.begin(), power.end());

        for (int i = 0, a = -1, b = -1, c = -1; i < n; ++i) {

            dp[i] += power[i];

            if (i - 1 >= 0 && power[i] != power[i - 1]) {

                if (a >= 0 && power[i] - power[a] > 2)
                    dp[i] += dp[a];
                else if (b >= 0 && power[i] - power[b] > 2)
                    dp[i] += dp[b];
                else if (c >= 0 && power[i] - power[c] > 2)
                    dp[i] += dp[c];
            }

            if (i + 1 < n && power[i + 1] != power[i]) {

                c = b;
                b = a;
                a = i;

            } else if (i + 1 < n)
                dp[i + 1] = dp[i];

            if (i - 1 >= 0)
                dp[i] = max(dp[i], dp[i - 1]);
        }

        return dp[n - 1];
  
    }
};