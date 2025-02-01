class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();

        for(int row=0;row<rows;row++){
            for(int col=1;col<cols;col++){
                matrix[row][col]+=matrix[row][col-1];
            }
        }

        // Now we will find the total number of submatrices with sum == target(leetcode 560) 
        int result=0;
        for(int s_col=0;s_col<cols;s_col++){
            for(int j=s_col;j<cols;j++){
                unordered_map<int,int>mp;
                mp[0]=1;
                int cumSum=0;
                for(int row=0;row<rows;row++){
                    cumSum+=matrix[row][j]-(s_col>0?matrix[row][s_col-1]:0);//imp
                    if(mp.find(cumSum-target)!=mp.end()){
                        result+=mp[cumSum-target];
                    }
                    mp[cumSum]++;
                }
            }
        }

        return result;
    }
};