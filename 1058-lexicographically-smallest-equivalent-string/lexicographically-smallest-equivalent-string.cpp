class Solution {
public:
    class Dsu {
        public:
        vector<int> parent;
        vector<int> rank;
        Dsu() {
            parent.resize(26, -1);
            rank.resize(26, 0);
            for (int i = 0; i < 26; i++) {
                parent[i] = i;
            }
        }
        int Find(int u) {
            if (parent[u] == u)
                return u;
            return parent[u] = Find(parent[u]);
        }
        void Union(int u, int v) {
            int parentU = Find(u);
            int parentV = Find(v);
            if (parentU == parentV)
                return;
            if (parentU > parentV)
                parent[parentU] = parentV;
            else if (parentU < parentV)
                parent[parentV] = parentU;
            else {
                parent[parentU] = parentU;
                rank[parentU]++;
            }
        }
    };
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        Dsu d;
        for (int i = 0; i < n; i++) {
            d.Union(s1[i] - 'a', s2[i] - 'a');
        }
        string ans;
        for (auto it : baseStr) {
            ans += char(d.Find(it-'a')+'a');
        }
        return ans;
    }
};