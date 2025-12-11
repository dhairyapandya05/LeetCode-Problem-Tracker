class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& building) {
        int n2 = building.size();

        vector<int>rowFirst(n+1,-1);
        vector<int>rowLast(n+1,-1);
        vector<int>columnFirst(n+1,-1);
        vector<int>columnLast(n+1,-1);

        set<pair<int,int>>s;
        
        for(int i=0;i<n2;i++){
            s.insert({building[i][0],building[i][1]});

            if(rowFirst[building[i][0]]==-1)rowFirst[building[i][0]]=building[i][1];
            else rowFirst[building[i][0]]=min(rowFirst[building[i][0]], building[i][1]);

            rowLast[building[i][0]]=max(rowLast[building[i][0]], building[i][1]);

            if(columnFirst[building[i][1]]==-1)columnFirst[building[i][1]]=building[i][0];
            else columnFirst[building[i][1]]=min(columnFirst[building[i][1]], building[i][0]);

            columnLast[building[i][1]]=max(columnLast[building[i][1]], building[i][0]);
        }

        int ans=0, i, j;
        for(int k=0;k<n2;k++){
            i = building[k][0];
            j = building[k][1];
            if(s.find({i,j})!=s.end() &&
                rowFirst[i]<j && rowLast[i]>j && 
                columnFirst[j]<i && columnLast[j]>i)ans++;
        }


        return ans;
    }
};