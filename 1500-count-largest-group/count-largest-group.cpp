class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int, int> mp;
        int maxCount = 0;
        int count = 0;
        for (int start = 1; start <= n; start++) {
            int digitS = digitSum(start);
            mp[digitS]++;
            if (mp[digitS] == maxCount) {
                count++;

            } else if (mp[digitS] > maxCount) {
                maxCount = mp[digitS];
                count = 1;
            }
        }
        return count;
    }
};