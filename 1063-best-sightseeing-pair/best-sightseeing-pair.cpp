class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        if (n < 2)
            return values[0] + values[1] + 0 - 1;
        int maxValueIplusI=values[0]+0;
        int result=0;
        for (int i =1; i <n; i++) {
            int x=values[i]-i;
            int y=maxValueIplusI;
            result = max(result,x+y);
            maxValueIplusI=max(maxValueIplusI,values[i]+i);
        }
        // int maxScore = INT_MIN;
        // for (int i = 1; i < n; i++) {
        //     maxScore = max(maxScore, prefixMax[i - 1] + values[i] - i);
        // }

        return result;
    }
};