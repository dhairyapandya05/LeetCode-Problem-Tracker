class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        long long ans=0;
        int n=weights.size();
        vector<long long int>cost;
        for(int i=1;i<n;i++){
            cost.push_back(weights[i]+weights[i-1]); 
        }
        sort(cost.begin(),cost.end());
        int m=n-1;
        long long int sumbegin = accumulate(cost.begin(), cost.begin() + (k - 1), 0LL);
        long long int sumend = accumulate(cost.end() - (k - 1), cost.end(), 0LL);
        return sumend- sumbegin;
    }
};