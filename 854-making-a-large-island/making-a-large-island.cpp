class Solution {
public:
 vector<int> rank, parent, size;

   void DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
// 0 ko 1 bnane se dynamic graph bnega so we use disjoint set
    int largestIsland(vector<vector<int>>& grid) {
        
     

        // hr componenet ka size nikl lnge phir ek 0 ko 1 se fill kr kr 4direction me componenet dekh lnge agr milah toh add 1+size of componenets
        int n=grid.size();
           DisjointSet(n*n);

vector<pair<int,int>>drc={{0,1},{1,0},{0,-1},{-1,0}};

// connect component

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

if(grid[i][j]==0){
    continue;
}

// connect by traversing all 4 direction
for(auto dir:drc){

int nx=i+dir.first;
int ny=j+dir.second;

if(nx<n && nx>=0 && ny>=0 && ny<n && grid[nx][ny]==1){
// every vertex is represented as a number (i,j)-> n*i+j;
unionBySize(i*n+j,nx*n+ny);

}


}


            }
        }

        int maxi=INT_MIN;

// now u have size for beach component prepared 
// now fill every 0 with 1 and then check

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

if(grid[i][j]==1){
    continue;
}

set<int> s;

// set isliyer bna rhe hai tki agr kisi bhi drcn me same hi component wle ka liye ek bar se jyada addition na ho

// like 0 surrounded with 1in left and right which are part of same component to dono nhi sirk ek add hoga 


// connect by traversing all 4 direction
for(auto dir:drc){

int nx=i+dir.first;
int ny=j+dir.second;

if(nx<n && nx>=0 && ny>=0 && ny<n ){
if(grid[nx][ny]==1){

s.insert(findUPar(nx*n+ny));

}


}


}

// now take the size of component with the parebts in the setand add 


int ans=1;

for(auto it:s){
    ans+=size[findUPar(it)];
}


maxi=max(ans,maxi);

            }
        }

// it may happen that all are part of same component 
// so

// Special Case Handling: If the grid is already a single large island (i.e., a single connected component of 1s), there will be no 0s to flip to 1s. The main part of the algorithm focuses on flipping 0s to 1s to form the largest possible island. However, if no flips are possible because there are no 0s, the largest island is simply the largest component of 1s already present.

for(int i=0;i<n*n;i++){

maxi=max(maxi,size[findUPar(i)]);

}


return maxi;
    }
};