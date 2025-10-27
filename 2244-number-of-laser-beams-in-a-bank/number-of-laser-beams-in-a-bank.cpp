class Solution {
public:
    
    int numberOfBeams(vector<string>& bank) {
        int c = 0, b = 0,s = 0;
        for(int i = 0 ; i<bank.size() ; i++)
        {          
            for(int j = 0 ; j<bank[i].size() ; j++)
            {
                if(bank[i][j]=='1') b++;
            }
           if(b>0)
           {
                s += b*c;
                c = b;
           }
            b = 0;
        }

        return s;
    }
    
};