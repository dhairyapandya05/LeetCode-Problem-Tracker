class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.length();
        vector<int>prefixN(n,0);
        vector<int>suffixY(n,0);

        if(customers[0]=='N')
        prefixN[0]=1;

        if(customers[n-1]=='Y')
        suffixY[n-1]=1;

        for(int i=1;i<n;i++){
            prefixN[i]=prefixN[i-1]+((customers[i]=='N')?1:0);
        }
        for(int i=n-2;i>=0;i--){
            suffixY[i]=suffixY[i+1]+((customers[i]=='Y')?1:0);
        }
        int miniHr=0;
        int minipanalty=INT_MAX;
        for(int i=0;i<=n;i++){
            int prefixcollisions=0;
            int suffixcollisions=0;

            if(i-1>=0)
            prefixcollisions=prefixN[i-1];

            if(i<n)
            suffixcollisions=suffixY[i];

            int totalpanalty=prefixcollisions+suffixcollisions;

            if(totalpanalty<minipanalty){
                minipanalty=totalpanalty;
                miniHr=i;
            }


        }
        return miniHr;
    }
};