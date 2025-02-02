class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int>roomUsedCount(n,0);
        vector<long long>lastFreeTime(n,0);
        sort(meetings.begin(),meetings.end());
        int m=meetings.size();
        for(int i=0;i<m;i++){
            int start=meetings[i][0];
            int end=meetings[i][1];
            int duration=end-start;
            bool found=false;
            long long earlyendRoomTime=LLONG_MAX;
            int earlyEndRoom =0;
            for(int room=0;room<n;room++){
                if(start>=lastFreeTime[room]){
                    found=true;
                    lastFreeTime[room]=end;
                    roomUsedCount[room]++;
                    break;
                }
                // also we will find out the minimum among them 
                if(earlyendRoomTime>lastFreeTime[room]){
                    earlyendRoomTime=lastFreeTime[room];
                    earlyEndRoom =room;
                }
            }
            if(!found){
                lastFreeTime[earlyEndRoom]+=duration;
                roomUsedCount[earlyEndRoom]++;
            }
            

        }
        int maxusedRoomIdx=(max_element(roomUsedCount.begin(),roomUsedCount.end())-roomUsedCount.begin());
        return maxusedRoomIdx;
    }
};