class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int result=0;
        for(int& it:left){
            result=max(result,it);
        }
        for(int& it:right){
            result=max(result,n-it);
        }
        return result;
    }
};