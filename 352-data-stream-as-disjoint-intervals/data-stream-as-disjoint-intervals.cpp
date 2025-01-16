class SummaryRanges {
public:
    set<int>st;
    SummaryRanges() {
        st.clear();
    }
    
    void addNum(int value) {
        st.insert(value); // log(n)
    }
    
    vector<vector<int>> getIntervals() {
        vector<int>nums(st.begin(),st.end());
        int n=st.size();
        vector<vector<int>> result;
        for(int i=0;i<n;i++){
            int left=nums[i];
            while(i<n-1 and nums[i]+1 == nums[i+1]){
                i++;
            }
            result.push_back({left,nums[i]});
        }
        return result;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */