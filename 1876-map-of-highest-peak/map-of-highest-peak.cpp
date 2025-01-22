class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> temp(m, vector<int>(n,-1));
        queue<pair<int,int>> q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isWater[i][j]){
                    q.push({i,j});
                    temp[i][j]=0;
                }
            }
        }

        int curr_row,curr_col,curr_val;
        int new_row, new_col;
        while(!q.empty()){
            curr_row = q.front().first;
            curr_col = q.front().second;
            curr_val = temp[curr_row][curr_col];
            q.pop();

            vector<int> row_mover={0,-1,0,1};
            vector<int> col_mover={-1,0,1,0};

            for(int i=0; i<4; i++){
                new_row = curr_row+row_mover[i];
                new_col = curr_col+col_mover[i];
                if(new_row>=0 && new_row<m && new_col>=0 && new_col<n){
                    if(temp[new_row][new_col]==-1){
                        temp[new_row][new_col] = curr_val+1;
                        q.push({new_row , new_col});
                    }
                }
            }


        }
        return temp;
    }
};