class Solution {
public:
    string clearStars(string s) {
        //map keep tracks of the smallest character to the left and it's index
        map<char,vector<int>>mp;
        //arr contains the index of character's to be excluded as per rule
        vector<int>arr;
        //iterate and compute arr
        for(int i=0;i<s.size();++i){
            if(s[i]=='*'){
                auto pair=mp.begin();
                int ind=pair->second.size()-1;
                //compute the index of smallest character till now closer to current index
                arr.push_back(pair->second[ind]);
                mp[pair->first].pop_back();
                if(mp[pair->first].size()==0){
                    mp.erase(pair->first);
                }
            }
            else mp[s[i]].push_back(i);
        }
        string ans="";
        //sort the indices
        sort(begin(arr),end(arr));
        int ind=0;
        //compute the result
        for(int i=0;i<s.size();++i){
            if(s[i]=='*') continue;
            else if(ind<arr.size() && arr[ind]==i){
                ind++;
                continue;
            }
            else ans+=s[i];
        }
        return ans;
    }
};