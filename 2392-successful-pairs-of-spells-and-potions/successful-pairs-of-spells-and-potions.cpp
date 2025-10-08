class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        int m=potions.size();
        sort(potions.begin(), potions.end());

        vector<int>ans(n, 0);

        for(int i=0; i<n; i++){
            int lo=0, hi=m-1,tmp=0;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                long long pro=(long long)((long long)spells[i]*(long long)potions[mid]);
                if(pro>=success){
                    tmp=m-mid;
                    hi=mid-1;
                }else lo=mid+1;
            }
            ans[i]=tmp;
        }

        return ans;        
    }
};