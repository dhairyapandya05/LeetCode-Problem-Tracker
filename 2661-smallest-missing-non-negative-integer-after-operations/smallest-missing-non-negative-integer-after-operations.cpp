class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] < 0) mp[((nums[i]%value)+value)%value]++;
            else mp[nums[i]%value]++;
        }
        for(int i=0; i<n; i++){
            int temp = i%value;
            if(mp.count(temp)){
                mp[temp]--;
                if(mp[temp] == 0){
                    mp.erase(temp);
                }
            }else{
                return i;
            }
        }
        return n;
    }
};