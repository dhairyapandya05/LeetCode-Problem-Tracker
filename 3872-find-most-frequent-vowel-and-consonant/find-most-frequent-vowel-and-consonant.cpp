class Solution {
public:
    int maxFreqSum(string s) {
        int n = s.length();
        
        // Map to store frequency of each character
        unordered_map<char, int> freq;
        
        // String containing all vowels
        string vowels = "aeiou";
        
        // Variables to track max frequencies
        int maxVowelFreq = 0, maxConsonantFreq = 0;
        
        // Count frequency of each character in the string
        for (int i = 0; i < n; i++) {
            freq[s[i]]++;
        }
        
        // Iterate over the frequency map
        for (auto it : freq) {
            // If character is a vowel and has higher frequency, update maxVowelFreq
            if (vowels.find(it.first) != string::npos && it.second > maxVowelFreq) {
                maxVowelFreq = it.second;
            }
            // If character is a consonant and has higher frequency, update maxConsonantFreq
            else if (vowels.find(it.first) == string::npos && it.second > maxConsonantFreq) {
                maxConsonantFreq = it.second;
            }
        }
        
        // Return the sum of max vowel and consonant frequencies
        return maxVowelFreq + maxConsonantFreq;
    }
};