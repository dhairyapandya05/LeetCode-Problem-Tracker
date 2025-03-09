class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int,int> map;
        vector<vector<int>> result ;
        for(vector<int> ele : nums1) {
            map[ele[0]] = ele[1] ;
        }
        for(vector<int> ele : nums2) {
            map[ele[0]] += ele[1] ;
        }
        for(auto ele : map) {
            result.push_back({ele.first,ele.second});
        }
        sort(result.begin(),result.end()) ;
        return result;
    }
};