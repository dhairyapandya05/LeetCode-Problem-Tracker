class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l=0;
        int i=0,n=nums.size(),j=n-1;
        vector<int>temp (n);

        while(i<=j){
            if(nums[l]%2==0){
                temp[i++]=nums[l];
            }
            else{
                temp[j--]=nums[l];
            }
            l++;
        }
        return temp;
    }
};