class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        unordered_map<int,int> mp;
        vector<int> visitedr(n,0),visitedc(m,0);
        int t=arr.size();
        for(int i=0;i<t;i++){
            int val=arr[i];
            mp[val]=i;
        }
        int minIdx=t-1;
        for(int r=0; r<n; r++)
        {
            int lastIdx=INT_MIN;
            for(int c=0; c<m; c++)
            {
                int val=mat[r][c];
                int idx=mp[val];
                lastIdx=max(lastIdx,idx);
            }
            minIdx=min(minIdx,lastIdx);
        }


        for(int c=0; c<m; c++)
        {
            int lastIdx=INT_MIN;
            for(int r=0; r<n; r++)
            {
                int val=mat[r][c];
                int idx=mp[val];
                lastIdx=max(lastIdx,idx);
            }
            minIdx=min(minIdx,lastIdx);
        }
        return minIdx;
    }
};