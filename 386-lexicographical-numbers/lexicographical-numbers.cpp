class Solution {
public:
    void solve(int currnum, int n,vector<int>& result) {
        if(currnum>n){
            return;
        }
        result.push_back(currnum);
        for(int i=0;i<=9;i++){
            int num=(currnum*10)+i;
            if(num>n){
                return;
            }
            solve(num,n,result);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for (int curr = 1; curr <= 9; curr++) {
            solve(curr, n, result);
        }
        return result;
    }
};