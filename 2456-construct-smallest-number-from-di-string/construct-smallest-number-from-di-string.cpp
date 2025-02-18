class Solution {
public:
    string smallestNumber(string pattern) {
        stack<char> st;
        string ans="";
        int n = pattern.size();
        int counter = 1;
        for (int i = 0; i <= n; i++) {
            st.push(counter + '0');
            counter++;
            if (i == n or pattern[i] == 'I') {
                while (!st.empty()) {
                    ans += st.top();
                    st.pop();
                }
            }
        }
        return ans;
    }
};