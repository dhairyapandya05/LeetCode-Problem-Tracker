class Solution {
public:
    int countscore(vector<vector<int>>& img1, vector<vector<int>>& img2,int& xoffset,int& yoffset){
        int n=img1.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int tocheckX=i+xoffset;
                int tocheckY=j+yoffset;
                if(tocheckX<0 or tocheckY<0 or tocheckX>=n or tocheckY>=n) continue;
                if(img1[i][j]==1 and img2[tocheckX][tocheckY]==1){
                    count++;
                }
            }
        }
        return count;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int ans=0;
        for(int i=-n+1;i<n;i++){
            for(int j=-n+1;j<n;j++){
                int score=countscore(img1,img2,i,j);
                ans=max(ans,score);
            }
        }
        return ans;
    }
};