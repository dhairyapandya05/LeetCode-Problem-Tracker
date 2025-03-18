class Solution {
public:
    void updateBitCounts(vector<int> &bitCounts, int number, int delta){
        for(int i = 0; i < 32; i++){
            if(number & (1 << i)){
                bitCounts[i] += delta;
            }
        }
    }

    bool isValidBitCount(vector<int> &bitCounts){
        for(int count : bitCounts){
            if(count > 1) return false;
        }
        return true;
    }

    int longestNiceSubarray(vector<int>& nums) {
        int leftPointer = 0;
        int rightPointer = 0;
        int maxLength = 1;
        int arraySize = nums.size();
        vector<int> bitCounts(32, 0);

        while(rightPointer < arraySize) {
            updateBitCounts(bitCounts, nums[rightPointer], 1);

            while(leftPointer < rightPointer && !isValidBitCount(bitCounts)) {
                updateBitCounts(bitCounts, nums[leftPointer], -1);
                leftPointer++;
            }

            maxLength = max(maxLength, rightPointer - leftPointer + 1);
            rightPointer++;               
        }

        return maxLength;
    }
};