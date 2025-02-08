class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> mp;
        unordered_map<int, int> colorfreqmp;

        int n = queries.size();
        vector<int> result;
        set<int> st;
        for (auto q : queries) {
            int ball=q[0];
            int color=q[1];
            if(mp.find(ball)!=mp.end()){
                // yae ball hum pahalae bhi mil chuka hai aab vapas aaya hai 
                int oldcolor=mp[ball];
                if(colorfreqmp[oldcolor]==1){
                    colorfreqmp.erase(oldcolor);
                }else{
                    colorfreqmp[oldcolor]--;
                }
            }
            mp[ball]=color;
            colorfreqmp[color]++;
            result.push_back(colorfreqmp.size());
        }

        return result;
    }
};