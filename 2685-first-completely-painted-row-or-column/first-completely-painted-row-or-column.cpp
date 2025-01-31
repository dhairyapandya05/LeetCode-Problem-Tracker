class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int nr = mat.size();
        int nc = mat[0].size();
        std::unordered_map<int, pair<int,int>> coords;
        std::vector<int> visitedr(nr,0),visitedc(nc,0);
        for(int r=0; r<nr; r++)
        {
            for(int c=0; c<nc; c++)
            {
                coords[mat[r][c]] = {r,c};
            }
        }
        int e=0;
        for(e=0; e<arr.size(); e++)
        {
            auto [r,c] = coords[arr[e]];
            if(++visitedr[r]==nc || ++visitedc[c]==nr) return e;
        }
        return arr.size();
    }
};