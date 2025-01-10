class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int,vector<int>>mp;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        vector<int> ans;
        int i=0;
        int k=0;
        for(auto it:mp){for(auto ele:it.second){cout<<ele<<" ";}cout<<endl;}
        for(auto& it:mp){
            if(k%2==0){
                reverse(it.second.begin(),it.second.end());
            }
            for(auto& ele:it.second){
                ans.push_back(ele);
            }
            k++;
        }
        return ans;
    }
};