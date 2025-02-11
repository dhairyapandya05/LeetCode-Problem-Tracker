class Solution {
public:
    int maxChunksToSorted(vector<int>& nums) {
        int n=nums.size();
        int chunks=0;
        int maxTillNow=-1;
        for(int i=0;i<n;i++){
            maxTillNow=max(maxTillNow,nums[i]);
            if(maxTillNow==i) chunks++;
        }
        return chunks;
    }
};