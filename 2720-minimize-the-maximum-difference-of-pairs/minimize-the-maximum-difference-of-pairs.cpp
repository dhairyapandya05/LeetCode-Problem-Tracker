class Solution {
public:
    bool check(vector<int>& nums, int p, int x){
        int count = 0;
        
        int i = 0;
        while(i < nums.size() - 1){
            if(nums[i+1] - nums[i] <= x){
                count++;
                i += 2;
            }
            else
                i++;
            
            if(count >= p)
                return true;
        }

        return false; 
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        int low  = 0, high = nums[n-1] - nums[0], ans = 0;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(check(nums, p, mid)){
                ans = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }

        return ans;
    }
};