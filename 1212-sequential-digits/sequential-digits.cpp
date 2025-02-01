class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> qe;
        vector<int> result;
        for (int i = 1; i < 9; i++) {
            qe.push(i);
        }
        while (!qe.empty()) {
            auto it = qe.front();
            qe.pop();
            if (it >= low and it <= high) {
                result.push_back(it);
            }
            int lastdigit = (it % 10);
            if (lastdigit + 1<= 9) {
                int newNumber = (it * 10) + (lastdigit + 1);
                qe.push(newNumber);
            }
        }
        return result;
    }
};