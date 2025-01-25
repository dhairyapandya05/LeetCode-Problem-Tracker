class Solution {
public:
    static bool comparator(int a, int b) {
        return a%2 < b%2; //a%2 will be 0 if it's even and since we do a%2 < b%2, hence a will come first if it's even
    }
    
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(begin(nums), end(nums), comparator);
        
        return nums;
    }
};