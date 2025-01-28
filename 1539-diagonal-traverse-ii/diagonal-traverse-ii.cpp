class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        queue<pair<int,int>>qe;
        int n=nums.size();
        int m=nums[0].size();

        qe.push({0,0});
        vector<int>result;
        while(!qe.empty()){
            auto temp=qe.front();
            int row=temp.first;
            int col=temp.second;

            qe.pop();
            result.push_back(nums[row][col]);
            if(col==0 and row+1<nums.size()){
                qe.push({row+1,col});
            }
            if(col+1<nums[row].size()){
                qe.push({row,col+1});
            }
        }
        return result;
    }
};