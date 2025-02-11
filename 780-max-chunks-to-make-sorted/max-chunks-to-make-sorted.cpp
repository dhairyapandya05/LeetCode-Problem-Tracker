class Solution {
public:
    int maxChunksToSorted(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix=nums;
        vector<int>suffix=nums;
        for(int i=1;i<n;i++){
            prefix[i]=max(prefix[i-1],prefix[i]);
        }
        for(int i=n-2;i>=0;i--){
            
            suffix[i]=min(suffix[i],suffix[i+1]);
        }
        int chunks=0;
        for(int i=0;i<n;i++){
            int pahaleaeKaMax=(i-1>=0)?prefix[i-1]:-1;
            int baadKaMin=suffix[i];
            if(pahaleaeKaMax<baadKaMin){
                chunks++;
            }
        }
        return chunks;
    }
};