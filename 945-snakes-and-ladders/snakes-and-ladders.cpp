class Solution {
public:
    pair<int,int> getCoordi(int num){
        int rt=(num-1)/n;
        int rb=(n-1)-rt;
        int c=(num-1)%n;
        if((n%2==1 and rb%2==1) or (n%2==0 and rb%2==0)){
            c=n-1-c;
        }
        return make_pair(rb,c);
    }
    int n;
    int snakesAndLadders(vector<vector<int>>& board) {
        n=board.size();
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        queue<int> que;
        int steps=0;
        visited[n-1][0]=true;
        que.push(1);
        while(!que.empty()){
            int N=que.size();
            while(N--){
                int x=que.front();
                que.pop();
                if(x==n*n) return steps;
                for(int i=1;i<=6;i++){
                    int val=x+i;
                    if(val>n*n) break;
                    pair<int,int>coord=getCoordi(val);
                    int r=coord.first;
                    int c=coord.second;
                    if(visited[r][c]==true) continue;
                    visited[r][c]=true;
                    if(board[r][c]==-1) {
                        que.push(val);
                    }
                    else{ 
                        que.push(board[r][c]);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};