class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(auto it:nums){
            count+=(((to_string(it).length())%2)==0);
        }
        return count;
    }
};