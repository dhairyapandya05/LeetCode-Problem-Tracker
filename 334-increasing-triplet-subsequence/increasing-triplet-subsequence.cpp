class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int num1=INT_MAX,num2=INT_MAX,num3=INT_MAX;
        for(auto it:nums){
            num3=it;
            if(num1>=num3){
                num1=num3;
            }
            else if(num2>=num3){
                num2=num3;
            }
            else{
                // num1 num2 set hai 
                return true;
            }
        }
        return false;
    }
};