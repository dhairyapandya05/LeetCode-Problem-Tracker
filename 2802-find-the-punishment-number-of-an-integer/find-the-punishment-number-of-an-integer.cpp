// class Solution {
// public:
//     bool ispossible(int target, const string &s, int i, long long sum) {
//         if (i >= s.length()) return sum == target;
//         if (sum > target) return false;

//         bool ans = false;
//         for (int j = i; j < s.length(); j++) {
//             long long part = stoll(s.substr(i, j - i + 1));
//             if (part > target) break; 
//             ans |= ispossible(target, s, j + 1, sum + part);
//         }
//         return ans;
//     }

//     int punishmentNumber(int n) {
//         int sum = 0;
//         for (int i = 1; i <= n; i++) {
//             string s = to_string(i * i);
//             if (ispossible(i, s, 0, 0)) {
//                 sum += i * i; 
//             }
//         }
//         return sum;
//     }
// };

class Solution {
public:
    bool ispossible(int target, const string &s, int i, long long sum,vector<vector<int>>&dp) {
        if (i >= s.length()) return sum == target;
        if (sum > target) return false;
        if(dp[i][sum]!=-1)
        return dp[i][sum];
        bool ans = false;
        for (int j = i; j < s.length(); j++) {
            long long part = stoll(s.substr(i, j - i + 1));
            if (part > target) break; 
            ans |= ispossible(target, s, j + 1, sum + part,dp);
        }
        return dp[i][sum]=ans;
    }

    int punishmentNumber(int n) {
        int sum = 0;
       
        for (int i = 1; i <= n; i++) {
            string s = to_string(i * i); 
            vector<vector<int>>dp(s.size()+1,vector<int>(i+1,-1));
            if (ispossible(i, s, 0, 0,dp)) {
                sum += i * i; 
            }
        }
        return sum;
    }
};