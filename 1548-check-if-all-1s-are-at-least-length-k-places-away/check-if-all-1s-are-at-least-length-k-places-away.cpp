class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int l = -(k+1), r = 0;
        for (int r = 0; r < n ;++r ){
            if (nums[r]){
                if (r - l <= k) return false;
                else l = r;
            }
        }
        return true;
    }
};