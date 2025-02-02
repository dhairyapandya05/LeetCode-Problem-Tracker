class Solution {
public:
    int findMaxLength(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mp;
        int maxlength=0;
        mp[0]=-1;
        int currSum=0;
        for(int i=0;i<n;i++){
            currSum+=(arr[i]==0?-1:1);
            if(mp.find(currSum)!=mp.end()){
                int length=i-mp[currSum];
                maxlength=max(maxlength,length);
            }
            else{
            mp[currSum]=i;
            }
        }
        return maxlength;
    }
};