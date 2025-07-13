class Solution {
public:
    string robotWithString(string s) {
        int i=0;
        string ans="";
        int n=s.length();
        vector<char>minChartoRight(n);
        minChartoRight[n-1]=s[n-1];
        for(int i=n-2;i>=0;i--){
            minChartoRight[i]=min(minChartoRight[i+1],s[i]);
        }
        string t="";
        while(i<n){
            t.push_back(s[i]);
            char minCahracter=(i+1<n)?minChartoRight[i+1]:s[i];
            while(!t.empty() and t.back() <= minCahracter){
                ans.push_back(t.back());
                t.pop_back();
            }
            i++;
        }
        while(!t.empty()){
            ans.push_back(t.back());
            t.pop_back();
        }
        return ans;
    }
};