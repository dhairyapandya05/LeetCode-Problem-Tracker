class Solution {
public:
    int numberOfWays(string corridor) {
        long long ans=1;
        long long MOD = 1e9+7;
        long long total_ways=0;
        long long last_seat_idx=-1;
        for(int i=0; i<corridor.size();i++){
            if(corridor[i]=='S'){
                total_ways++;
                if(total_ways > 2&& total_ways%2!=0){
                    long long ways_todivide = i-last_seat_idx;
                    ans = (ans * ways_todivide) % MOD;
                }
            last_seat_idx=i;
            }
        }
        if(total_ways==0 || total_ways%2!=0){
            return 0;
        }
        return (int)ans;
    }
};