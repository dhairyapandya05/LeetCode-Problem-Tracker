class Solution {
public:
    int minOperations(vector<int>& nums) {
        int k=3;
        unordered_map<int, int> mp;
        int n = nums.size();
        int flips = 0;
        deque<int> isFlipped;
        int flipcountfrompastfori = 0;
        for (int i = 0; i < n; i++) {
            if (i - k >= 0) { // abhi isFlipped[i-k] valla ith index par impack nahi bana raha hoga to usko minus karaegae
                flipcountfrompastfori -= (isFlipped.front());
                isFlipped.pop_front();
            }
            if (flipcountfrompastfori % 2 == nums[i]) {
                //  we need to flip
                if (i + k > n)
                    return -1;

                flipcountfrompastfori++;
                flips++;
                isFlipped.push_back(1); // here 1 means we have flipped that particular bit
            } else {
                isFlipped.push_back(0); // here 1 means we have not flipped that particular bit
            }
        }
        return flips;
    }
};