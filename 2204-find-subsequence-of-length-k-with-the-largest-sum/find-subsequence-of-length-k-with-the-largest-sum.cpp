class Solution {
public:
    //TC = O(n)  &&   SC = O(n)
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();

        if(n == k) { //EDGE CASE
            return nums;
        }

        vector<int> temp(nums); //temp = nums
        vector<int> ans;

        nth_element(temp.begin(), temp.begin() + k - 1, temp.end(), greater<int>()); //kth Largest At Right Index  [Average TC = O(n)]

        int kthLargest = temp[k-1];
        int countKthLargest = count(temp.begin(), temp.begin() + k, kthLargest); //Ktak KA Count (IMP EDGE CASE)

        for(int &num: nums) {
            if(num > kthLargest) {
                ans.push_back(num);
            }
            else if(num == kthLargest && countKthLargest > 0) {  //countKthLargest => Special && IMP EDGE CASE
                ans.push_back(num);
                countKthLargest--;
            }

            if(ans.size() == k) { //Check EVERY TIME K Size
                break;
            }
        }

        return ans;
    }
};