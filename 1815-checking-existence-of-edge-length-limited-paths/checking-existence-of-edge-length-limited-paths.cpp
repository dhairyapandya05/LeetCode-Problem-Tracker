class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    
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
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int t=queries.size();
        for(int i=0;i<t;i++){
            queries[i].push_back(i);
        }
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        auto cmp=[&](vector<int>v1, vector<int>& v2){
            return v1[2]<v2[2];
        };
        sort(queries.begin(),queries.end(),cmp);
        sort(edgeList.begin(),edgeList.end(),cmp);
        int j=0;
        int m=edgeList.size();
        vector<bool> result(t);
        for(int i=0;i<t;i++){
            int threshold=queries[i][2];
            while(j<m and edgeList[j][2]<threshold){
                unionSets(edgeList[j][0],edgeList[j][1]);
                j++;
            }
            result[queries[i][3]]=(find(queries[i][0])==find(queries[i][1]))?true:false;
        }
        return result;
    }
};