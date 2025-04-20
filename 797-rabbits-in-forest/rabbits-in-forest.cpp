class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>mp;
        for(auto it:answers){
            mp[it]++;
        }
        int ans=0;
        for(auto it:mp){
            int groupSize=(it.first+1);
            int numberofGroups=ceil((it.second*1.0)/groupSize);
            ans+=numberofGroups*groupSize;
        }
        return ans;
    }
};