class Solution {
public:
    
  bool check(char ch){
        return (ch=='a' || ch=='A' || ch=='e' || ch=='E' 
        || ch=='i' || ch=='I' || ch=='o' || ch=='O' 
        || ch=='u' || ch=='U');
    }
 
    string sortVowels(string s) {
        
        vector<int> v;
        vector<int> u;

        int n =s.length();
       
        for(int i=0;i<n;i++){
            if(check(s[i])){
                // v.push_back({ch,i});
                v.push_back(s[i]);
                u.push_back(i);
            }
        }  

        sort(v.begin(),v.end());

      for(int i=0;i<v.size();i++){
        s[u[i]]=v[i];
      }

        return s;
    }
};