class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        
        int t=travel.size();
        for(int i=1;i<t;i++){
            travel[i]=travel[i]+travel[i-1];
        }
        int pickuptime=0;
        int n=garbage.size();
        for(int i=0;i<n;i++){
            pickuptime+=garbage[i].length();
        }
        int lastp=0;
        int lastg=0;
        int lastm=0;
        for(int i=0;i<n;i++){
            if(find(garbage[i].begin(),garbage[i].end(),'G')!=garbage[i].end()){
                lastg=i;
            }
            if(find(garbage[i].begin(),garbage[i].end(),'P')!=garbage[i].end()){
                lastp=i;
            }
            if(find(garbage[i].begin(),garbage[i].end(),'M')!=garbage[i].end()){
                lastm=i;
            }
        }
        cout<<pickuptime<<"d   ";
        pickuptime+=((lastg==0)?0:travel[lastg-1]);
        cout<<pickuptime<<"g   ";

        pickuptime+=((lastp==0)?0:travel[lastp-1]);
        cout<<pickuptime<<"p   ";

        pickuptime+=((lastm==0)?0:travel[lastm-1]);
        cout<<pickuptime<<"m   ";

        return pickuptime;
    }
};