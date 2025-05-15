class Solution {
public:
    int N;
    class UnionFind {
    public:
        vector<int> parent;
        vector<int> rank;
        UnionFind(int n) {
            parent.resize(n);
            rank.resize(n,0);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
        int find(int u) {
            if (parent[u] == u) {
                return parent[u];
            }
            return parent[u] = find(parent[u]);
        }

        void Union(int v, int u) {
            int u_parent = find(u);
            int v_parent = find(v);
            if (u_parent == v_parent) {
                return;
            } else {
                if (rank[u_parent] > rank[v_parent]) {
                    parent[v_parent] = u_parent;
                    // rank[v_parent]++;
                } else if (rank[v_parent] > rank[u_parent]) {
                    parent[u_parent] = v_parent;
                    // rank[u_parent]++;
                } else {
                    parent[u_parent] = v_parent;
                    rank[v_parent]++;
                }
            }
        }
    };

    int KruscalsAlgo(vector<vector<int>>& edges, int sub, int add) {
        int sum = 0;
        UnionFind uf(N);
        if (add != -1) {
            uf.Union(edges[add][0], edges[add][1]);
            sum += edges[add][2];
        }
        for (int i=0;i<edges.size();i++) {
            vector<int>temp=edges[i];
            if (i == sub) {
                continue;
            }
            int u = temp[0];
            int v = temp[1];
            int w = temp[2];
            int u_parent = uf.find(u);
            int v_parent = uf.find(v);
            if (u_parent != v_parent) {
                uf.Union(u, v);
                sum += w;
            }
        }
        for (int i = 0; i < N; i++) {
            if (uf.find(i) != uf.find(0))
                return INT_MAX;
        }
        return sum;
    }
    vector<vector<int>>
    findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        N = n;
        for (int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }
        auto cmp = [&](vector<int>& a, vector<int>& b) { return a[2] < b[2]; };
        sort(edges.begin(), edges.end(), cmp);
        int original = KruscalsAlgo(edges, -1, -1);
        vector<int> critical;
        vector<int> pseudoCritical;
        for(int i = 0; i < edges.size(); i++) {
          
            if(KruscalsAlgo(edges, i, -1) > original) //Skipping ith edge
                critical.push_back(edges[i][3]); 
            
            else if(KruscalsAlgo(edges, -1, i) == original) // Force add ith edge
                pseudoCritical.push_back(edges[i][3]);
        }
        vector<vector<int>> ans = {critical, pseudoCritical};
        return ans;
    }
};