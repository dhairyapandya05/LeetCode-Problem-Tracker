class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastindex(26, -1);
        vector<int> ans;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            lastindex[int(s[i] - 'a')] = i;
        }
        int i = 0, j = 0;
        for(int k=0;k<n;k++){
            j=max(j,lastindex[int(s[k]-'a')]);
            if(k==j){
                ans.push_back(j-i+1);
                i=j+1;
            }
        }
        return ans;
    }
};