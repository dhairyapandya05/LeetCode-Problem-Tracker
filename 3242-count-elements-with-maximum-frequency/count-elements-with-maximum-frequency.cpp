class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;
        unordered_map<int, int> mpp;

        // Step 1: Count frequency of each element
        for(int it : nums){
            mpp[it]++;
        }

        // Step 2: Find maximum frequency
        for(auto it = mpp.begin(); it != mpp.end(); it++){
            if(it->second >= maxi){
                maxi = it->second;
            }
        }

        // Step 3: Sum all frequencies that match the maximum frequency
        for(auto it : mpp){
            if(it.second == maxi){
                sum += it.second;
            }
        }

        return sum;
    }
};