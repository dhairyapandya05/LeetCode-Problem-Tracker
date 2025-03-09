class Solution {
public:
    vector<long long> dp; // Memoization only based on index

    long long solve(int i, vector<vector<int>>& rides) {
        if (i >= rides.size()) return 0;
        if (dp[i] != -1) return dp[i]; // Check memoized result

        // Option 1: Skip this ride
        long long notTake = solve(i + 1, rides);

        // Option 2: Take this ride and find the next available ride using binary search
        int nextRide = lower_bound(rides.begin() + i + 1, rides.end(), rides[i][1], 
            [](const vector<int>& ride, int target) { return ride[0] < target; }) - rides.begin();

        long long take = (rides[i][1] - rides[i][0] + rides[i][2]) + solve(nextRide, rides);

        return dp[i] = max(take, notTake);
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end()); // Sort by start time
        dp.assign(rides.size(), -1); // Memoization for ride indices
        return solve(0, rides);
    }
};
