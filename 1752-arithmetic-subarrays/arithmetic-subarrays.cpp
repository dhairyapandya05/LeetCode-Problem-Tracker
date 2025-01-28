class Solution {
public:
    bool check(vector<int>& arr){
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int d=arr[1]-arr[0];
        for(int i=2;i<n;i++){
            if(arr[i]-arr[i-1]!=d){
                return false;
            }
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> result;
        int n=l.size();
        for(int i=0;i<n;i++){
            int s=l[i];
            int e=r[i];
            vector<int>arr(begin(nums)+s,begin(nums)+e+1);
            bool checkForAp=check(arr);
            result.push_back(checkForAp);

        }

        return result;
    }
};