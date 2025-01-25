class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n=arr.size();
        int winner=arr[0];
        int winstreak=0;
        int maxele=*max_element(arr.begin(),arr.end());
        if(k>=n-1){
            return maxele;
        }
        for(int i=1;i<n;i++){
            if(arr[i]>winner){
                winner=arr[i];
                winstreak=1;
            }
            else{
                winstreak++;
            }
            if(winstreak==k or winner==maxele){
                return winner;
            }
        }
        return winner;
    }
};