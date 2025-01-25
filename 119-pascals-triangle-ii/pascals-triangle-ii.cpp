class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // vector<int>res={1};
        // if(rowIndex==0){
        //     return res;
        // }
        // for(int i=1;i<=rowIndex;i++){
        //     vector<int> nxtRow(i+1,0);
        //     for(int k=0;k<res.size();k++){
        //         nxtRow[k]+=res[k];
        //         nxtRow[k+1]+=res[k];
        //     }
        //     res=nxtRow;// traversing downwards
        // }
        // return res;
        vector<int>prev;
        for(int i=0;i<rowIndex+1;i++){
            vector<int>curr(i+1,1);
            for(int j=1;j<i;j++){
                curr[j]=prev[j]+prev[j-1];
            }
            prev=curr;
        }
        return prev;
    }
};