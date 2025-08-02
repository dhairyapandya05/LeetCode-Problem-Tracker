#define ll long long
class Solution {
public:
    // vector<int> vec; // which elements need to change location
    // map<int,int> seen;
    // int calc(map<int,int>& f1,map<int,int>& f2){
    //     for(auto &[k,v] : f1){
    //         if(seen[k]) continue;
    //         seen[k] = 1;
    //         if((f1[k]+f2[k])%2==1) return -1;
    //         if(f1[k]!=f2[k]){
    //             int cnt = abs(f1[k] - f2[k]);
    //             cnt = cnt/2;
    //             while(cnt--){
    //                 vec.push_back(k);
    //             }
    //         }
    //     }
    //     return 1;
    // }
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int> f;
        int mn = 1e9;
        for(auto x : basket1){ 
            f[x]++; mn = min(mn, x);
        }
        for(auto x : basket2){ 
            f[x]--; mn = min(mn, x);
        }
        // if(calc(f1,f2)==-1) return -1;
        // if(calc(f2,f1)==-1) return -1;
        vector<int> vec; 
        for(auto &[k,v] : f){
            if(abs(v)%2==1) return -1;
            int cnt = abs(v); // cnt = -2
            cnt/=2;
            while(cnt--){
                vec.push_back(k);
            }
        }
        sort(vec.begin(),vec.end());
        ll ans = 0;
        int swap = 0;
        for(int i=0;i<vec.size()/2;i++){
            if(vec[i]<=2*mn){
                swap += 2; ans += vec[i];
            }
        }
        ans += (ll)(vec.size()-swap)*mn;
        return ans;
    }
};