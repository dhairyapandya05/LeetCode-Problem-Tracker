class Solution {
public:
    vector<string> spellchecker(vector<string>& w, vector<string>& q) {
        map<string,int> ori, lower, vowel ;

        for(int i=0;i<w.size();i++)
        {
            if(ori.find(w[i]) == ori.end()) ori[w[i]] = i ;


            string str = w[i] ;
            transform(str.begin(), str.end(), str.begin(), ::tolower) ;
            if(lower.find(str) == lower.end()) lower[str] = i ;
            

            for(int i=0;i<str.size();i++)
            {
                char ch = str[i] ;
                if(ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u') 
                {
                    str[i] = '#' ;
                }
            }
            if(vowel.find(str) == vowel.end()) vowel[str] = i ;
        }

        vector<string> ans ;

        for(int i=0;i<q.size();i++)
        {
            string s = q[i] ;
            if(ori.find(s) != ori.end()) {ans.push_back(w[ori[s]]) ; continue ;}


            transform(s.begin(), s.end(), s.begin(), ::tolower) ;
            if(lower.find(s) != lower.end()) {ans.push_back(w[lower[s]]) ; continue;}


            for(int j=0;j<s.size();j++) if(s[j]=='a' or s[j]=='e' or s[j]=='i' or s[j]=='o' or s[j]=='u') s[j] = '#' ;


            if(vowel.find(s) != vowel.end()) ans.push_back(w[vowel[s]]) ;
            else ans.push_back("") ;
        }
        return ans ;
    }
};