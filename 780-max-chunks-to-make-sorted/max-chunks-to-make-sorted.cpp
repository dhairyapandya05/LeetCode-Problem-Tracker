class Solution {
public:
    int maxChunksToSorted(vector<int>& nums) {
        int n=nums.size();
        int cumSum=0,origSum=0,chunks=0;
        for(int i=0;i<n;i++){
            cumSum+=nums[i];
            origSum+=i;
            if(origSum==cumSum){
                chunks++;
            }
        }
        return chunks;
    }
};