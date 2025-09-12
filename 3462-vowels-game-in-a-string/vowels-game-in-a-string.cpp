class Solution {
public:
    bool isVowel(char ch){
        return (ch=='a')||(ch=='e')||(ch=='i')||(ch=='o')||(ch=='u');
    }
    bool doesAliceWin(string s) {
        int numVol=0;
        for(int i=0;i<s.length();i++){
            if(isVowel(s[i])){
                return true;
            }
        }
        return false;
    }
};