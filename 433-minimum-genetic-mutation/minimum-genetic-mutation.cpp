class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> wordBank(bank.begin(), bank.end());
        queue<pair<string, int>> qe;
        vector<char> charpossible = {'A', 'C', 'G', 'T'};
        unordered_set<string> visited;
        visited.insert(startGene);
        qe.push({startGene, 0});
        while (!qe.empty()) {
            int N = qe.size();
            while (N--) {
                auto fr = qe.front();
                qe.pop();
                string cmp = fr.first;
                int steps = fr.second;
                if (cmp == endGene) {
                    return steps;
                }
                for (int i = 0; i < 8; i++) {
                    for (auto ch : charpossible) {
                        string orig = cmp;
                        orig[i] = ch;
                        if (visited.find(orig) == visited.end() and
                            wordBank.find(orig) != wordBank.end()) {
                            qe.push({orig, steps + 1});
                            visited.insert(orig);
                        }
                    }
                }
            }
        }
        return -1;
    }
};