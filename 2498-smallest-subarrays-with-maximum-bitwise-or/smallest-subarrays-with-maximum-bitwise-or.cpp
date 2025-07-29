class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int r = 0;

        vector<vector<int>> nn(nums.size()+2,vector<int>(33,0));

        for (int i = nums.size()-1;i>=0;i--) {
            for (int b = 0;b<=31;b++) {
                if ((1<<b) & nums[i]) {
                    nn[i][b] = nn[i+1][b] + 1;
                } else {
                    nn[i][b] = nn[i+1][b];
                }
            }
        }
        int ongoing = 0;

        vector<int> res;

        vector<int> c(32,0);
        for (int l = 0;l<nums.size();l++) {
            while (true) {
                int f = 0;
                for (int i = 0;i<31;i++) {
                if (!((1<<i) & ongoing) && nn[r][i]>0) {

                    for (int b = 0;b<31;b++) {
                        if ((1<<b) & nums[r]) {
                            ongoing = ongoing | (1<<b);
                            c[b]++;
                        }
                    }

                    r++;
                    f++;
                    break;
                }
                }
                
                if (f==1) {
                    continue;
                }

                break;
            }

            for (int i = 0;i<31;i++) {
                if ((1<<i) & nums[l]) {
                    if (c[i]==1) {
                        ongoing &= (~(1<<i));
                    }

                    c[i]--;
                }
            }
            res.push_back(max(r-l,1));


            
        }

        return res;
    }
};