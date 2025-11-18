class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        for (int i = 0; i < n; )
        {
            int b1 = bits[i];

            if (b1 == 1)
            {
                i+=2;
            }
            else if (b1 == 0 && i == n-1)
            {
                return true;
            }
            else
            {
                i++;
            }
        }
        return false;
    }
};