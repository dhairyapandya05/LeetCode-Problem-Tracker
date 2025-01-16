class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        vector<bool>visited(n,false);
        visited[0]=true;
        int steps=0;
        queue<int>qe;
        qe.push(0);
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        while(!qe.empty()){
            int N=qe.size();
            while(N--){
                int curr=qe.front();
                qe.pop();
                int left=curr-1;
                int right=curr+1;
                if(curr==n-1){
                    return steps;
                }
                if(left>=0 and !visited[left]){
                    qe.push(left);
                    visited[left]=true;
                }
                if(right<=n-1 and !visited[right]){
                    qe.push(right);
                    visited[right]=true;
                }
                for(int &idx:mp[arr[curr]]){
                    if(!visited[idx]){
                        qe.push(idx);
                        visited[idx]=true;
                    }
                }
                mp.erase(arr[curr]);

            }
            steps++;
        }
        return steps;

    }
};