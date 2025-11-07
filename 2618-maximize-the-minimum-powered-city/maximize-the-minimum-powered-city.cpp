class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long>PrefixSum(n + 1, 0);
        vector<long long>InitialPower(n, 0);
        for(int i=1; i < n+1; i++){
            PrefixSum[i] =  PrefixSum[i-1] + stations[i-1];
        }
        for(int i=0; i < n; i++){
            int left = max(0, i - r);
            int right = min(n, i + r + 1);
            InitialPower[i] =  PrefixSum[right] - PrefixSum[left];
        }

        long long left = 0;
        long long right = *max_element(InitialPower.begin(), InitialPower.end()) + k;//3 7 11 9 5 // 0 13 // 6 // 2 // 4
        // 2 0 0 -2 0
        auto canAchieve = [&](long long target) -> bool {
            bool result = true;
            long long used = 0;
            long long windowSum = 0;
#if 1
            queue<pair<int, long long>> q;

            for (int i = 0; i < n; i++) {
                while (!q.empty() && q.front().first <= i) {
                    windowSum -= q.front().second;
                    q.pop();
                }

                long long currentPower = InitialPower[i] + windowSum;

                if (currentPower < target) {
                    long long need = target - currentPower;
                    used += need;
                    if (used > k) {
                        result = false;
                        break;
                    }else{
                        windowSum += need;
                        int expire = min(n, i + 2*r + 1);
                        q.push({expire, need});
                    }
                }
            }
#else
        vector<long long> diff(n+1, 0);
        for (int i = 0; i < n; i++){
            windowSum += diff[i];
            long long currentPower = InitialPower[i] + windowSum;
            if (currentPower < target){
                long long need = target - currentPower;
                used += need;
                if (used > k) {
                    result = false;
                    break;
                }else{
                    windowSum += need;
                    int expire = min(n, i + 2*r + 1);
                    diff[i] += need;
                    diff[expire] -= need;
                }
            }
        }
#endif
            return result;
        };

        while (left <= right){
            long long mid = (left + right) / 2;
            if (canAchieve(mid))left = mid + 1;
            else right = mid - 1;
        }
        return right;
    }
};