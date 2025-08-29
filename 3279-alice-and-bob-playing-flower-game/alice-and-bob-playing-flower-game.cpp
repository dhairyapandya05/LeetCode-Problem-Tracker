class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ans = 0;
        ans = ceil((double)n/2)*(m/2) + ceil( (double) m/2)*(n/2);
        return ans;
    }
};