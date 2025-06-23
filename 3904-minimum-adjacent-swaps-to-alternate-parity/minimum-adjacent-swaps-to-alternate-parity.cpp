class Solution {
public:
int findSwaps(vector<int>& index){
    int swaps=0;
    for(int i=0;i<index.size();i++){
        swaps+=abs((2*i)-index[i]);
        // cout<<"Swaps: "<<swaps<<" and i "<<i;
    }
    return swaps;
}
    int minSwaps(vector<int>& nums) {
        int t=nums.size();
        vector<int>evenIndex;
        vector<int>oddIndex;
        for(int i=0;i<t;i++){
            if(nums[i]&1)oddIndex.push_back(i);
            else evenIndex.push_back(i);
        }
        int m=evenIndex.size();
        int n=oddIndex.size();
        if(abs(m-n)>1) return -1;
        if(m>n){
            return findSwaps(evenIndex);
        }
        else if(n>m){
            // cout<<"Yes";
            return findSwaps(oddIndex);
        }
        return min(findSwaps(evenIndex),findSwaps(oddIndex));
    }
};