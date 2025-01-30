class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        int k=n/4;
        for(int i=0;i<n;){
            int j=(upper_bound(arr.begin(),arr.end(),arr[i])-arr.begin());
            int freq=j-i;
            if(freq>k) return arr[i];
            else i=j;
        }
        return -1;
    }
};