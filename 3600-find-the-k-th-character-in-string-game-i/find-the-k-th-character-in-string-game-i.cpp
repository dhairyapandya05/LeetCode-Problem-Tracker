class Solution {
public:
    char kthCharacter(int k) {
    string ans = "a";
    while (ans.length() < k) {
        string temp = "";
        for (auto it : ans) {
            int charI = it - 'a';
            charI++;
            charI %= 26;

            temp += char(charI + 'a');
        }
        ans += temp;
        cout << ans << "Ans" << endl;
    }
    cout << "Value of K" << k << " in string " << ans << endl;
    return ans[k - 1];
}
};