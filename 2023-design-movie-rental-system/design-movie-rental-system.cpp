struct PairHash {
    size_t operator()(const pair<int,int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};
struct PairComp {
    bool operator()(const pair<int,pair<int,int>>& a,
                    const pair<int,pair<int,int>>& b) const {
        if (a.first != b.first) return a.first < b.first;  
        if (a.second.first != b.second.first) return a.second.first < b.second.first; 
        return a.second.second < b.second.second;                   
    }
};
class MovieRentingSystem {
public:
    unordered_map<int,set<pair<int,int>>> mpp;
    unordered_map<pair<int,int>,int,PairHash> shopmPrice;
    unordered_map<pair<int,int>,int,PairHash> rentedMovies;
    set<pair<int,pair<int,int>>,PairComp> st;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto it:entries){
            mpp[it[1]].insert({it[2],it[0]});
            shopmPrice[{it[0],it[1]}] = it[2];
        }
    }
    
    vector<int> search(int movie) {
        auto &it = mpp[movie];
        vector<int> ans;

        int cnt = 0;
        for(auto temp:it){
            ans.push_back(temp.second);
            cnt++;
            if(cnt == 5)break;
        }

        return ans;
    }
    
    void rent(int shop, int movie) {
        int price = shopmPrice[{shop,movie}];
        rentedMovies[{shop,movie}] = price;
        shopmPrice.erase({shop,movie});
        mpp[movie].erase({price,shop});
        st.insert({price,{shop,movie}});
    }
    
    void drop(int shop, int movie) {
        int price = rentedMovies[{shop,movie}];
        shopmPrice[{shop,movie}] = price;
        rentedMovies.erase({shop,movie});
        mpp[movie].insert({price,shop});
        st.erase({price,{shop,movie}});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int cnt = 0;

        for(auto it:st){
            ans.push_back({it.second.first,it.second.second});
            cnt++;
            if(cnt == 5)break;
        }

        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */