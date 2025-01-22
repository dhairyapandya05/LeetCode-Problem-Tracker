class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>data;
        for(int i=0;i<n;i++){
            int totalsolders=0;
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    totalsolders++;
                }
            }
            data.push_back({totalsolders,i});
        }
        auto cmp=[&](vector<int>& v1, vector<int>& v2){
            if(v1[0]==v2[0]){
                return v1[1]<v2[1];
            }
            return v1[0]<v2[0];
        };
        sort(data.begin(),data.end(),cmp);
        vector<int>ans;
        int i=0;
        while(k--){
            ans.push_back(data[i][1]);
            i++;
        }
        return ans;
    }
};