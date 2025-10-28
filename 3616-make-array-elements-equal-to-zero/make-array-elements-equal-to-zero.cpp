class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        // Using long long for ls and total to prevent potential integer overflow
        long long ls = 0, total = 0;
        int cases = 0;

        // First pass: calculate total sum
        for(int num : nums){
            total += num;
        }

        // Second pass: calculate left/right sums and count cases
        for (int num : nums) {
            // Calculate right sum efficiently
            long long rs = total - ls - num;
            
            if (num == 0) {
                if (ls == rs) {
                    cases += 2;
                } else if (ls == rs - 1 || ls - 1 == rs) {
                    cases++;
                }
            }
            // Update left sum for the next iteration
            ls += num;
        }
        return cases;
    }
};