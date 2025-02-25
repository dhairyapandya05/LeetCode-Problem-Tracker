class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int MOD=1e9+7;
        int even =1;
        int odd=0;
        int result=0;
        int n=arr.size();
        vector<int>prefixSum(n);
        prefixSum[0]=arr[0];

        for(int i=1;i<n;i++) 
        prefixSum[i]=prefixSum[i-1]+arr[i];


        for(int i=0;i<n;i++){
            if((prefixSum[i]%2)==1){
                result=(result+even)%MOD;
                odd++;
            }
            else if((prefixSum[i]%2)==0){
                result=(result+odd)%MOD;
                even++;
            }
        }
        return result;
    }
};