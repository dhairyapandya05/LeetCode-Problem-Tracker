class Solution {
public:
    bool solve(vector<vector<char>> &board){
        int n=board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                //chack for empty cell
                if(board[i][j]=='.'){
                    //try to fill the values renging from 1 to 9
                    for(char value='1';value<='9';value++){
                        //check for safety
                        if(isSafe(i,j,board,value)){
                            //insert
                            board[i][j]=value;
                            //recursion sambhal laega
                            bool remainingBoardSolution=solve(board);
                            if(remainingBoardSolution==true){
                                return true;
                            }
                            else{
                                //back track
                                board[i][j]='.';
                            }

                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool isSafe(int &row,int &col,vector<vector<char>> &board,char value){
        int n=board.size();
        for(int i=0;i<n;i++){
            //row check
            if(board[row][i]==value){
                return false;
            }
            //column check
            if(board[i][col]==value){
                return false;
            }
            //3 * 3 box check
            if(board[3*(row/3) + (i/3)][3 * (col/3) + (i%3)]==value){
                return false;
            }
        }
        return true;
    }
};