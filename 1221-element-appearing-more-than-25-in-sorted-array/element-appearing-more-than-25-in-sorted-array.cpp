class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        int k=n/4;
        for(int i=0;i<n;i++){
            if(i+k<n and arr[i]==arr[i+k]) return arr[i];
        }
        return -1;
    }
};