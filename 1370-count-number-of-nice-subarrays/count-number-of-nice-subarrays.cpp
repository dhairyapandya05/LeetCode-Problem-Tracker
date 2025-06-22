class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> prefix;
        prefix[0] = 1;
        int sum = 0, count = 0;
        for (int num : nums) {
            sum += (num%2);
            count += prefix[sum - k];
            prefix[sum]++;
        }
        return count;
    }

   
};