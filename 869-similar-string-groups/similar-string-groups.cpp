class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    bool isSimilar(string s, string t){
        if(s.length()!=t.length()) return false;
        int diff=0;
        int n=t.length();
        for(int i=0;i<n;i++){
            if(s[i]!=t[i])diff++;
        }
        return diff==0 or diff==2;
    }

    
    int find(int i){
        if(parent[i]==i){
            return i;
        }
        return parent[i]=find(parent[i]);
    }
    
    void unionSets(int u,int v){
        int x_parent=find(u);
        int y_parent=find(v);
        if(x_parent!=y_parent){
            if(rank[x_parent] > rank[y_parent]){
                parent[y_parent]=x_parent;
            }
            else if(rank[x_parent] < rank[y_parent]){
                parent[x_parent]=y_parent;
            }
            else{
                parent[x_parent]=y_parent;
                rank[y_parent]++;
            }
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        unordered_map<int,vector<int>>adj;
        int n=strs.size();
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){ 
            for(int j=i+1;j<n;j++){
                if(isSimilar(strs[i], strs[j])){
                    adj[j].push_back(i);
                    adj[i].push_back(j);
                }
            }
        }
        int groups=n;
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isSimilar(strs[i],strs[j]) and find(i)!=find(j)){
                    unionSets(i,j);
                    groups--;
                }
            }
        }



        return groups;
    }
};