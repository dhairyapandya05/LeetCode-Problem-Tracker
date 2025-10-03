class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap)
    {
        int r = heightMap.size();
        int c = heightMap[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> visited(r,vector<int>(c,0));

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(i==0 || i==r-1 || j==0 || j==c-1)
                {
                    pq.push({heightMap[i][j],{i,j}});
                    visited[i][j]=true;
                }
            }
        }

        int volume = 0;
        int minBoundaryHeight=0;
        while(!pq.empty())
        {
            int h = pq.top().first;
            int R = pq.top().second.first;
            int C = pq.top().second.second;
            pq.pop();
            minBoundaryHeight = max(minBoundaryHeight,h);

            int dirR[] = {0,0,-1,1};
            int dirC[] = {-1,1,0,0};

            for(int i=0; i<4; i++)
            {
                int rr = R + dirR[i];
                int cc = C + dirC[i];

                if(rr>=0 && rr<=r-1 && cc>=0 && cc<=c-1 && !visited[rr][cc])
                {
                    pq.push({heightMap[rr][cc],{rr,cc}});
                    visited[rr][cc]=true;
                    if(heightMap[rr][cc]<minBoundaryHeight) volume += minBoundaryHeight-heightMap[rr][cc];
                }
            }
        }
        return volume;
    }
};