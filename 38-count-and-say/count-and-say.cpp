class Solution {
public:
    string solve(string prev,int n){
        // cout<<prev<<endl;
        if(n==1){
            return prev;
        }
        string resultantstring="";
        char x= '-1';
        int freq=0;
        for(int i=0;i<prev.length();i++){
            if(i==0){
                x=prev[i];
                freq=1;
                continue;
            }
          if(prev[i]==x){
            freq++;
            
          }
          else{
             resultantstring+=to_string(freq)+x;
            //  cout<<resultantstring<<endl;
             x=prev[i];
             freq=1;
          }
            
        }
        resultantstring+=to_string(freq)+x;
        return solve(resultantstring,n-1);
    }
    string countAndSay(int n) {
        if(n==1) return "1";
        return solve("1",n);
        //11132
    }
};