class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int,int>mp;
        for(auto it:changed){
            mp[it]++;
        }
        sort(changed.begin(),changed.end());
        int n=changed.size();
        if(n%2!=0) return {};
        vector<int>original;
        for(int i=0;i<n;i++){
            if(mp[changed[i]]==0) continue;
            if(mp[(2*changed[i])]==0) return {};
            cout<<changed[i]<<" '";
            original.push_back(changed[i]);
            mp[changed[i]]--;
            mp[(2*changed[i])]--;
        }
        return original;
    }
};