class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans =0;
        int temp=1;
        int n=colors.size();
        for(int i=1; i<=n+k-2 ;i++){
            if(colors[i%n]!=colors[(i-1+n)%n] ){
                temp++;
            }else{
                temp=1;
            }
            if(temp >=k){
                ans++;
            }
        }
        return ans;
    }
};