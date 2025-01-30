class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        int k=n/4;
        for(int i=k;i<n;i+=k){
            int curr=arr[i];
            int lowerbound=(lower_bound(arr.begin(),arr.end(),curr)-arr.begin());
            int upperbound=(upper_bound(arr.begin(),arr.end(),curr)-arr.begin());
            int freq=upperbound-lowerbound;
            if(freq>k) return curr;
        }
        return -1;
    }
};