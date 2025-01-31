class Solution {
public:
    int minimumLength(string s) {
        std::vector<std::queue<int>> q(26);
        for(int i=0;i<s.size();i++){
            int ch = s[i]-'a';
            if(q[ch].size()>=2){
                q[ch].pop();
            }
            else{
                q[ch].push(i);
            }
        }
        int ans=0;
        for(auto& c:q){
            ans+=c.size();
        }
        return ans;
    }
};