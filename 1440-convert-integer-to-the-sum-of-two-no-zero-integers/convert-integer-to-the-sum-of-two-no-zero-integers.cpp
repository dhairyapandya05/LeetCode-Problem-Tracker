class Solution {
public:
    bool hasNoZero(int num){
        while(num>0){
            int rem=num%10;
            if(rem==0) return false;
            num=num/10;
        }
        return true;
   }
    vector<int> getNoZeroIntegers(int n) {
        int a=n-1, b=1;
        while(a>=b){
            if(hasNoZero(a) and hasNoZero(b)){
                return {a, b};
            }
            else{
                a--;
                b++;
            }
        }
    return {};
    }
};