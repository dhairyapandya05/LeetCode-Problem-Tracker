class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        unordered_map<int,int>mp;
        int n=matrix.size();
        int m=matrix[0].size();


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mp.find(i-j)==mp.end()){
                    mp[i-j]=matrix[i][j];
                }
                else{
                    if(mp[i-j]!=matrix[i][j]) return false;
                }
            }
        }
        return true;
    }
};