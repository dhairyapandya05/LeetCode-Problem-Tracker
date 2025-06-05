class DisjointSet
{    
public: 
    vector<int> parent;
    vector<int> rank;

    DisjointSet()
    {
        parent.assign(26, -1);
        rank.assign(26, 0);
    }

    int findUp(int u)
    {
        if(parent[u] == -1) return u;
        return parent[u] = findUp(parent[u]);
    }

    void unionByRank(char u, char v)
    {
        int uU = findUp(u - 'a');
        int vV = findUp(v - 'a');
        if(uU == vV) return;

        if(uU < vV)   // Always keep lex smaller as parent
        {
            parent[vV] = uU;
        }
        else
        {
            parent[uU] = vV;
        }
    }

    char findMini(char ch)
    {
        return findUp(ch - 'a') + 'a';
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjointSet ds;
        for(int i = 0; i < s1.length(); i++)
        {
            ds.unionByRank(s1[i], s2[i]);
        }

        string res;
        for(char ch : baseStr)
        {
            res += ds.findMini(ch);
        }
        return res;
    }
};