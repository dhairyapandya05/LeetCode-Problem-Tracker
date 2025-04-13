class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastindex(26, -1);
        vector<int> ans;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            lastindex[int(s[i] - 'a')] = i;
        }
        int i = 0;
        while(i<n){
            int end=lastindex[s[i]-'a'];
            int j=i;
            while(j<end){
                end=max(end,lastindex[s[j]-'a']);
                j++;
            }
            ans.push_back(end-i+1);
            i=end+1;
        }
        return ans;
    }
};