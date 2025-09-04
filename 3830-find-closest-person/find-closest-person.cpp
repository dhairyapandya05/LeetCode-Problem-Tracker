class Solution {
public:
    int findClosest(int x, int y, int z) {
        int result;

        int differencexz = std::abs(x - z);
        int differenceyz = std::abs(y - z);

        if (differencexz > differenceyz) {
            result = 2;
        } else if (differencexz < differenceyz) {
            result = 1;
        } else {
            result = 0;
        }

        return result;
    }
};