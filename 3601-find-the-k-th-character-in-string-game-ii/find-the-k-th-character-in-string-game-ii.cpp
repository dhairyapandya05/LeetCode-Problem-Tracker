class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        

        int a=ceil(log2(k));
        int count=0;
        if(k==1) return'a';
        count+=operations[ceil(log2(k))-1];
        long long m=pow(2,a-1);
        long long res=k-m;

        while(res>1){
            k=res;
            count+=operations[ceil(log2(k))-1];
            m=pow(2,ceil(log2(k))-1);
            res=k-m;
        }
        count%=26;
        return 'a'+count;

    }
};