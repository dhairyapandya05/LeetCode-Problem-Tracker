class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long int res = 0;
        long long int len = 1;

        for (int i=0; i<prices.size(); i++){
            if (i > 0 && prices[i-1] - prices[i] == 1) len++;
            else len = 1;

            res += len;
        }

        return res;

    }
};