class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<pair<int,int>>intervals;
        int n=nums.size();
        for(int i=0;i<n;i++){
            intervals.push_back({nums[i]-k,nums[i]+k});
        }

        sort(intervals.begin(),intervals.end());
        deque<int>de;
        int maxBeauty=0;
        for(int i=0;i<n;i++){
            while(!de.empty() and de.front()<intervals[i].first){
                de.pop_front();
            }
            de.push_back(intervals[i].second);
            maxBeauty=max(maxBeauty,(int)de.size());
        }
        return maxBeauty;
    }
};