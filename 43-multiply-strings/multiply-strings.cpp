class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        vector<int>ans(num1.length()+num2.length(),0);
        for(int i=0;i<num1.length();i++){
            int carry=0;
            int start=i;
            for(int j=0;j<num2.length();j++){
                int d1=num1[i]-'0';
                int d2=num2[j]-'0';
                int tempans=(d1*d2)+carry+ans[start];
                int base=tempans%10;
                carry=tempans/10;
                ans[start++]=base;
            }
            if(carry!=0) ans[start]=carry;
        }
        for(auto it:ans) cout<<it;
        int i=ans.size()-1;
        string finalans="";
        while(i>0 and ans[i]==0) i--;
        for(int j=0;i>=0;j++,i--){
            finalans+=to_string(ans[i]);
        }
        return finalans;
    }
};