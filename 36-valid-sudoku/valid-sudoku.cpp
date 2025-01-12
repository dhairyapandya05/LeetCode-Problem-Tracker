class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        unordered_set<string>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='.') continue;
                string row= string(1,board[i][j])+ "got in"+ to_string(i)+"row";
                string col= string(1,board[i][j])+ "got in"+ to_string(j)+"col";
                string box= string(1,board[i][j])+ "got in"+ to_string(i/3)+"row and"+to_string(j/3)+"col";
                if(st.find(row)!=st.end() or st.find(col)!=st.end() or st.find(box)!=st.end()) 
                return false;

                st.insert(row);
                st.insert(col);
                st.insert(box);
            }
        }
        return true;
    }
};