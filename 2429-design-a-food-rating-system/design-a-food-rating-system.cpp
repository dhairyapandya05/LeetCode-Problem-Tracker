class SegmentTree {
private:
    vector<int> tree; 
    size_t n;
    vector<pair<int, string>> Data;

    int Max(pair<int, string>& a, int idxA, pair<int, string>& b, int idxB) {
        if(a.first != b.first) return a.first > b.first ? idxA : idxB;
        return a.second < b.second ? idxA : idxB;
    }

public: 
    SegmentTree(vector<pair<int, string>>& data) {
        Data = data;
        n = Data.size();
        tree.resize(4*n);
        build(0, 0, n-1);
    }

    void build(int idx, int l, int r) {
        if(l == r) {
            tree[idx] = l;
            return;
        }
        int mid = l + (r-l)/2;
        int leftNode = (idx<<1)+1, rightNode = (idx<<1)+2;

        build(leftNode, l, mid);
        build(rightNode, mid+1, r);

        tree[idx] = Max(Data[tree[leftNode]], tree[leftNode],
                        Data[tree[rightNode]], tree[rightNode]);
    }

    string highest() {
        return Data[tree[0]].second;
    }

    void update(int idx, int newRating) {
        updateTree(0, idx, newRating, 0, n-1);
    }

    void updateTree(int node, int idx, int newRating, int l, int r) {
        if(l == r) {
            Data[l].first = newRating;
            return;
        }
        int mid = l + (r-l)/2;
        int leftNode = (node<<1)+1, rightNode = (node<<1)+2;

        if(idx <= mid) updateTree(leftNode, idx, newRating, l, mid);
        else updateTree(rightNode, idx, newRating, mid+1, r);

        tree[node] = Max(Data[tree[leftNode]], tree[leftNode],
                         Data[tree[rightNode]], tree[rightNode]);
    }       
}; 

class FoodRatings {
private:
    unordered_map<string, SegmentTree*> segMap;
    unordered_map<string, string> cuisineMap;
    unordered_map<string, int> indexMap;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        unordered_map<string, vector<pair<int, string>>> mp;

        for(int i=0; i<foods.size(); i++) {
            cuisineMap[foods[i]] = cuisines[i];
            mp[cuisines[i]].push_back({ratings[i], foods[i]});
            indexMap[foods[i]] = mp[cuisines[i]].size()-1;
        }

        for(auto &[cuisine, data]: mp) {
            segMap[cuisine] = new SegmentTree(data);
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = cuisineMap[food];
        int idx = indexMap[food];
        segMap[cuisine]->update(idx, newRating);
    }
    
    string highestRated(string cuisine) {
        return segMap[cuisine]->highest();
    }
};