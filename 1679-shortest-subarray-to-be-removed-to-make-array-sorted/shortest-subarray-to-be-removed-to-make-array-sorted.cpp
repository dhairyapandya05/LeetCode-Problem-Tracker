class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        
        // Step 1: Find `j`, the start of the non-decreasing suffix
        // int j = n - 1;
        // while (j > 0 && arr[j] >= arr[j - 1]) j--;

        int j = n - 1;
for (; j >= 1; j--) {
    if (arr[j] < arr[j - 1]) break;
}
        
        // If the whole array is already sorted, no removal needed
        if (j == 0) return 0;
        
        int result = j; // Remove prefix [0, j-1]
        int i = 0;

        // Step 2: Try to merge increasing prefix (0 to i) with (j to n-1)
        while (i < n && (i == 0 || arr[i] >= arr[i - 1])) {
            while (j < n && arr[i] > arr[j]) j++;
            result = min(result, j - i - 1);
            i++;
        }
        
        return result;
    }
};
