class Solution {
public:
//     // 0,0
//     int func1( int r, int c, int n, vector<vector<int>>&fruits, int s){
//         if(r == n-1 && c==n-1){
//             if(s == n-1 ){
//                 int val = fruits[r][c];
//                 // fruits[r][c] = 0;
//                 return val;
//             }
//             else{
//                 return INT_MIN;
//             }
//         }
//         int val = fruits[r][c];
//         // fruits[r][c] = 0;
//         int a = INT_MIN;
//         int b = INT_MIN;
//         int x = INT_MIN;
//         if(r+1>=0 && r+1<n && c+1>=0 && c+1<n){
//             a = func1(r+1,c+1,n,fruits,s+1);
//         }
//         if(r+1>=0 && r+1<n && c>=0 && c<n){
//             b = func1(r+1,c,n,fruits,s+1);
//         }
//         if(r>=0 && r<n && c+1>=0 && c+1<n){
//             x = func1(r,c+1,n,fruits,s+1);
//         }
//         return val + max(a,max(b,x));
        
//     }
//     // 0, n-1
    int func2( int r, int c, int n, vector<vector<int>>&fruits, int s,vector<vector<int>>&dp){
        if(r == n-2 && c==n-1){
            if(s == n-2 ){
                return fruits[r][c];
            }
            else{
                return INT_MIN;
            }
        }
        if( s== n-2){
            return INT_MIN;
        }
        if(dp[r][c] != -1){
            return dp[r][c];
        }
        int val = fruits[r][c];
        // fruits[r][c] = 0;
        int a = INT_MIN;
        int b = INT_MIN;
        int x = INT_MIN;
        if(r+1>=0 && r+1<n && r<c&& c-1>=0 && c-1<n){
            a = func2(r+1,c-1,n,fruits,s+1,dp);
        }
        if(r+1>=0 && r+1<n && r<c && c>=0 && c<n){
            b = func2(r+1,c,n,fruits,s+1,dp);
        }
        if(r+1>=0 && r+1<n && r< c && c+1>=0 && c+1<n){
            x = func2(r+1,c+1,n,fruits,s+1,dp);
        }
        return dp[r][c] = val + max(a,max(b,x));
        
    }
//     // n-1, 0
    int func3( int r, int c, int n, vector<vector<int>>&fruits, int s,vector<vector<int>>&dp){
        if(r == n-1 && c==n-2){
            if(s == n- 2){
                return fruits[r][c];
            }
            else{
                return INT_MIN;
            }
        }
        if( s== n-2){
            return INT_MIN;
        }
        if(dp[r][c] != -1){
            return dp[r][c];
        }
        int val = fruits[r][c];
        // fruits[r][c] = 0;
        int a = INT_MIN;
        int b = INT_MIN;
        int x = INT_MIN;
        if(r-1>=0 && r-1<n && c+1>=0 && c+1<n && c<r){
            a = func3(r-1,c+1,n,fruits,s+1,dp);
        }
        if(r>=0 && r<n && c+1>=0 && c+1<n && c<r){
            b = func3(r,c+1,n,fruits,s+1,dp);
        }
        if(r+1>=0 && r+1<n && c+1>=0 && c+1<n && c<r){
            x = func3(r+1,c+1,n,fruits,s+1,dp);
        }
        return dp[r][c] = val + max(a,max(b,x));
        
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        // int ans = func1(0,0,n,fruits,0)+func2(0,n-1,n,fruits,0) + func3(n-1,0,n,fruits,0);
        // return ans-2*fruits[n-1][n-1];
        int a = fruits[0][0];
        for(int i = 1;i<=n-1;i++){
            a += fruits[i][i];
            fruits[i][i] = 0;
        }
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int a2 = func2(0,n-1,n,fruits,0,dp);
        for(auto &it:dp){
            fill(it.begin(),it.end(),-1);
        }
        int a3 = func3(n-1,0,n,fruits,0,dp);
        return a + a2+a3;

     
        // return a + b+c+fruits[n-1][n-1];


    }
};