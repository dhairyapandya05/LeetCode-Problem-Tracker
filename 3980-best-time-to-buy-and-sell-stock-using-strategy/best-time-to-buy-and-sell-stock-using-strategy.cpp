class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
       long long ans = -1e18;
       int n = prices.size();
       long long sum = 0;
       long long k_sum = 0;
       int cnt = k;
       for(int i = 0;i<n;i++){
         sum+= prices[i]*strategy[i];
         if(cnt>0){
           k_sum+= prices[i]*strategy[i];
           cnt--;
         }
       }
       ans = max(ans,sum);
       int start = 0;
       int end = start+k-1;
       long long ksum_updated = 0;
       for(int i = end;i>=start+k/2;i--){
          ksum_updated+= prices[i];
       }
       long long updated_sum = 0;
       while(end<n){
         if(start!=0){
              k_sum = k_sum+(prices[end]*strategy[end])-(prices[start-1]*strategy[start-1]);
              ksum_updated = ksum_updated+prices[end]-prices[(start+k/2)-1];
         }
         updated_sum = sum-k_sum+ksum_updated;
         ans = max(ans,updated_sum);
         start++;
         end++;
       }
       return ans;
    }
};