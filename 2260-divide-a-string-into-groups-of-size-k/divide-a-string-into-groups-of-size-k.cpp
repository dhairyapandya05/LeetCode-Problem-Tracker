class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.length();
        vector<string>dividedString;
        for(int i=0;i<n;i+=k){
            string subStr=s.substr(i,min(k,n-i));
            if(subStr.length()!=k){
            string added(k-subStr.length(),fill);
            subStr+=added;
            }
            dividedString.push_back(subStr);
        }
        return dividedString;
    }
};