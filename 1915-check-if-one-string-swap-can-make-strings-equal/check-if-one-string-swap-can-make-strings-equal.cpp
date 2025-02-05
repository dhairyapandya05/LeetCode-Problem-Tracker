class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n1=s1.length();
        int n2=s2.length();
        int defectiveidx1=-1;
        int defectiveidx2=-1;
        int cnt=0,diff1=0,diff2=0;
        if(n1!=n2) return false;
        for(int i=0;i<n1;i++){
            if(s1[i]!=s2[i]){
                cnt++;
                if(defectiveidx1==-1){
                    defectiveidx1=i;
                }
                else if(defectiveidx2==-1){
                    defectiveidx2=i;
                }
            }
            if(cnt>2) return false;
        }
        return (cnt==0 or ((defectiveidx1!=-1 and defectiveidx2!=-1) and s1[defectiveidx1]==s2[defectiveidx2] and s1[defectiveidx2]==s2[defectiveidx1]))?true:false;
    }
};