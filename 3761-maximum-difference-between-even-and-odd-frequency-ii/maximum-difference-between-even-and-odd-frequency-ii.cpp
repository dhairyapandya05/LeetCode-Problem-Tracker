class Solution 
{
public:
    int maxDifference(string s, int k) 
    {
        int n = s.size();
        int ans = INT_MIN;
        for (int a = 0; a <= 4; a++){
            for (int b = 0; b <= 4; b++) {
                if (a == b)continue;
                vector<int> s1(n+1), s2 (n+1);
                int mat[2][2] = {{INT_MIN, INT_MIN}, {INT_MIN, INT_MIN}};

                for (int i = 1; i <= n; i++){
                    s1[i] = s1[i - 1] + (s[i - 1] - '0' == a);
                    s2[i] = s2[i - 1] + (s[i - 1] - '0' == b);
                }

                for (int i = k, j = 0; i <= n; i++){
                    while (i - j >= k && s1[i] > s1[j] && s2[i] > s2[j]) {
                        mat[s1[j] % 2][s2[j] % 2] = max(mat[s1[j] % 2][s2[j] % 2], s2[j] - s1[j]);
                        j++;
                    }
                    if (mat[1-s1[i] % 2][s2[i] % 2] != INT_MIN){
                        ans = max(ans, (s1[i] - s2[i]) + mat[1-s1[i] % 2][s2[i] % 2]);
                    }
                }
            }
        }

        return ans == INT_MIN ? -1 : ans;
    }
};