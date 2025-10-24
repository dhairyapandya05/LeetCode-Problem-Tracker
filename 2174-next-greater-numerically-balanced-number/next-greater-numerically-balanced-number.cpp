class Solution {
public:
   bool freq(int num){
        map<int,int>mpp;
          while (num > 0) {
        int digit = num % 10;
        mpp[digit]++;
        num /= 10;

    }
      for (auto &p : mpp) {
          if(p.first!=p.second){
            return false;
          }
         
    }
    return true;
    
     }
    int nextBeautifulNumber(int n) {
       int i = n;
        while (true) {
            i++;
            if (freq(i))
                return i;
        }
        
    }
};