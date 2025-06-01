class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long res = 0;
        limit = min(n, limit);
        for(int i=0;i<=limit;i++){
            int rem = n-i;
            if(rem > (2LL*limit))continue;
            if(rem > limit)res += 2LL*limit - rem + 1;
            else res += rem + 1;
        }
        return res;
    }
};