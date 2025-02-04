class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int flips=0;
        int flipcountfrompastfori=0;
        // vector<bool> isFlipped(n,false);
        for(int i=0;i<n;i++){
            if(i-k>=0 and nums[i-k]==-1){ // abhi isFlipped[i-k] valla ith index par impack nahi bana raha hoga to usko minus karaegae
                flipcountfrompastfori--;
            }
            if(flipcountfrompastfori%2==nums[i]){
                //  we need to flip
                if(i+k>n) return -1;

                flipcountfrompastfori++;
                flips++;
                // isFlipped[i]=true;
                nums[i]=-1;
            }
        }  
        return flips;
    }
};