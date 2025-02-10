class Solution {
public:
    bool isVowel(char& ch){
        return ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int>prefixCompute(n,0);
        if (isVowel(words[0][0]) and isVowel(words[0][words[0].length()-1])) prefixCompute[0]=1;
        for(int i=1;i<n;i++){
            prefixCompute[i]=prefixCompute[i-1]+int(isVowel(words[i][0]) and isVowel(words[i][words[i].length()-1]));
            cout<<prefixCompute[i]<<" ";
        }
        int m=queries.size();
        vector<int>ans(m,0);
        for(int i=0;i<m;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            ans[i]=prefixCompute[r]-((l-1>=0)?prefixCompute[l-1]:0);
        }
        return ans;
    }
};