class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxArea=0;
        vector<int>prevHeights(m,0);
        for(int i=0;i<n;i++){
            vector<int>currHeights=matrix[i];
            for(int j=0;j<m;j++){
                if(currHeights[j]==1){
                    currHeights[j]+=prevHeights[j];
                }
            }
            vector<int>heights=currHeights;
            sort(heights.begin(),heights.end(),greater<int>());
            for(int i=0;i<m;i++){
                int height=heights[i];
                int width=i+1;
                int area=height*width;
                maxArea=max(maxArea,area);
            }
            prevHeights=currHeights;
        }
        return maxArea;
    }
};