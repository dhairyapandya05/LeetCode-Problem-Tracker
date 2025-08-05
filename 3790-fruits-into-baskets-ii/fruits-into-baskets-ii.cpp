class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans = fruits.size();
        for(int i = 0; i <fruits.size();i++){
            for(int j = 0 ; j < fruits.size();j++){
                if(fruits[i] <= baskets[j]){
                    ans--;
                    baskets[j]=-1;
                    break;
                }
            }
        }

        return ans;
    }
};