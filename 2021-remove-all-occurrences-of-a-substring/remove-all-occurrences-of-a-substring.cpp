class Solution {
public:
    string removeOccurrences(string s, string part) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        string answer = "";
        int n = s.size();
        int m = part.size();
        if (m > n) {
            return s;
        } else if (m == n && s == part) {
            return answer;
        }
        stack<char> st;

        char lastCh = part[m - 1];
        char tmp;
        string check = "";

        for (int i = 0; i < n; ++i) {
            tmp = s[i];
            if (tmp == lastCh) {
                st.push(tmp);
                stack<char> tmpSt;
                char tmpJ;
                int j = m - 1;
                while (j >= 0 && !st.empty()) {
                    tmpJ = st.top();
                    st.pop();
                    if (tmpJ == part[j]) {
                        tmpSt.push(tmpJ);
                    } else {
                        st.push(tmpJ);
                        break;

                    }
                    --j;
                }
                if (j >= 0) {
                    while (!tmpSt.empty()) {
                        st.push(tmpSt.top());
                        tmpSt.pop();
                    }
                }

            } else {
                st.push(tmp);
            }
        }
        while (!st.empty()) {
            answer.push_back(st.top());
            st.pop();
        }
        reverse(answer.begin(), answer.end());


        return answer;
    }
};