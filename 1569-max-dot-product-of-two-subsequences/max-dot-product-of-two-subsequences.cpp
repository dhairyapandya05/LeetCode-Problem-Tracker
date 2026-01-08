class Solution {
private:
    int max_pro(int idx1, int idx2, vector<int> &arr, vector<int> &brr, vector<vector<int>> &dp){
        if(idx1 < 0 || idx2 < 0){
            return INT_MIN;
        }

        if(dp[idx1][idx2] != INT_MIN){
            return dp[idx1][idx2];
        }

        int curr_pro = arr[idx1] * brr[idx2];
        int take = curr_pro;
        int next_call = max_pro(idx1-1, idx2-1, arr, brr, dp);
        if(next_call != INT_MIN){
            take = max(take, curr_pro + next_call);
        }

        int not_take = max(max_pro(idx1-1, idx2, arr, brr, dp), 
                           max_pro(idx1, idx2-1, arr, brr, dp));

        int ans = max(take, not_take);
        return dp[idx1][idx2] = ans;
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
        return max_pro(n-1, m-1, nums1, nums2, dp);
    }
};