class Solution {
public:
    int countTriples(int n) {
        int ans =0 ;
        for(int i =1 ; i<=n ;i++){
            for(int j=1 ; j<=n ; j++){
                int c2 = i*i + j*j ;
                int reqd = sqrt(c2) ;

                if(reqd * reqd == c2 && reqd <= n) ans ++ ; //here we have to check if the reqd is whole number 
            }
        }
        return ans ;
    }
};