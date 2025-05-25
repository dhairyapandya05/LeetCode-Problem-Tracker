class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        for (auto it : words) {
            mp[it]++;
        }
        int ans = 0;
        bool oddtaken = false;
        for (auto it : words) {
            string rev = it;
            reverse(rev.begin(), rev.end());
            if (it == rev) {
                if (mp[it] % 2 == 0) {
                    ans += (mp[it] * 2);
                    mp.erase(it);
                } else if (mp[it] % 2 == 1 and oddtaken == false) {
                    oddtaken = true;
                    ans += (mp[it] * 2);
                    mp.erase(it);
                }
                else{
                    ans += ((mp[it]-1) * 2);
                    mp.erase(it);
                }
            }
            if (mp.find(rev) != mp.end()) {
                ans += 4 * min(mp[it], mp[rev]);
                mp.erase(it);
                mp.erase(rev);
            }
        }
        return ans;
    }
};