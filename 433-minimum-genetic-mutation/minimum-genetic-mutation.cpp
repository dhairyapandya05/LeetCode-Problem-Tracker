class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> wordBank(bank.begin(), bank.end());
        queue<string> qe;
        vector<char> charpossible = {'A', 'C', 'G', 'T'};
        unordered_set<string> visited;
        int steps=0;
        visited.insert(startGene);
        qe.push(startGene);
        while (!qe.empty()) {
            int N = qe.size();
            while (N--) {
                string cmp = qe.front();
                qe.pop();
                if (cmp == endGene) {
                    return steps;
                }
                for (int i = 0; i < 8; i++) {
                    for (auto ch : charpossible) {
                        string mutate = cmp;
                        mutate[i] = ch;
                        if (visited.find(mutate) == visited.end() and
                            wordBank.find(mutate) != wordBank.end()) {
                            qe.push(mutate);
                            visited.insert(mutate);
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};