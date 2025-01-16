class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> mp(n+1,0);
        int ans=-1;
        int m=trust.size();
        for(int i=0;i<m;i++){
            mp[trust[i][0]]--;
            mp[trust[i][1]]++;
        }
        for(int i=1;i<=n;i++){
            if(mp[i]==n-1) return i;
        }
        return -1;
    }
};