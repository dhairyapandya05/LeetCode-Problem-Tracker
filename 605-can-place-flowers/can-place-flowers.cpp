class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int l) {
        int n=flowerbed.size();
        if(l==0) return true;

        for(int i=0;i<n;i++){
            if(flowerbed[i]==0){
                bool leftkhali=(i==0)|| (flowerbed[i-1]==0);
                bool rightkhali=(i==n-1)|| (flowerbed[i+1]==0);
                if(leftkhali and rightkhali){
                    flowerbed[i]=1;
                    l--;
                    if(l==0) return true;
                }
            }
        }
        return false;
    }
};