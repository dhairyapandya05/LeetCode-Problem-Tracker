class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start="";
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                start+=to_string(board[i][j]);
            }
        }
        string target="123450";
        queue<string>qe;
        qe.push(start);
        unordered_map<int,vector<int>>mp;// possible swappable state 
        mp[0]={1,3};
        mp[1]={0,2,4};
        mp[2]={1,5};
        mp[3]={0,4};
        mp[4]={1,3,5};
        mp[5]={2,4};
        unordered_set<string>visited;
        visited.insert(start);
        int level=0;
        while(!qe.empty()){
            int n=qe.size();
            while(n--){
                string curr=qe.front();
                qe.pop();
                if(curr==target) return level;

                int indexOfZero=curr.find('0');
                for(int swapIdx:mp[indexOfZero]){
                    string NewState=curr;
                    swap(NewState[indexOfZero],NewState[swapIdx]);
                    if(visited.find(NewState)==visited.end()){
                        qe.push(NewState);
                        visited.insert(NewState);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};