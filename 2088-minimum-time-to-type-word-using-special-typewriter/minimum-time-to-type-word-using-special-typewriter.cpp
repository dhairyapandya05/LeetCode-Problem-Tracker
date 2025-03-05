class Solution {
public:
    int minTimeToType(string word) {
        int n=word.length();
        int ans=n;
        int i=0;
        while(i<n){
            char prechar=(i==0)?'a':word[i-1];
            char currchar=word[i];
            ans+=min(26-abs(currchar-prechar),abs(currchar-prechar));
            cout<<ans<<" ";
            i++;
        }
        return ans;
    }
};