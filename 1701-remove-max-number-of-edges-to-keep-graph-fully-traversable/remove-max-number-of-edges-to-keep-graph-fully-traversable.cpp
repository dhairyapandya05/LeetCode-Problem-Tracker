class Solution {
public:
class Dsu{
    public:
    vector<int> parent;
    vector<int> rank;
    Dsu(int n){
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        rank.resize(n,0);
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
};
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int Alicegroups=n,Bobcompn=n;
        auto cmp=[&](vector<int>&v1, vector<int>&v2){
            return v1[0]>v2[0];
        };
        sort(edges.begin(),edges.end(),cmp);
        Dsu* alice= new Dsu(n+1);
        Dsu* bob= new Dsu(n+1);
        int count=0;
        for(auto it:edges){
            if(it[0]==2){
                //bob
                if(bob->find(it[2])!=bob->find(it[1])){
                    bob->unionSets(it[1],it[2]);
                    Bobcompn--;
                }
                else{
                    count++;
                }
            }
            else if(it[0]==1){
                // By Alice
                if(alice->find(it[2])!=alice->find(it[1])){
                    alice->unionSets(it[1],it[2]);
                    Alicegroups--;
                }
                else {
                    count++;
                }
            }
            else{
                // by both
                if(bob->find(it[2])!=bob->find(it[1])){
                    bob->unionSets(it[1],it[2]);
                    Bobcompn--;
                }
                if(alice->find(it[2])!=alice->find(it[1])){
                    alice->unionSets(it[1],it[2]);
                    Alicegroups--;
                }
                else{
                    count++;
                }
            }
        }
        return (Bobcompn==1 and Alicegroups==1) ?count:-1;
    }
};