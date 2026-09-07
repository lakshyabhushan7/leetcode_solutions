class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int freq[26] = {0}; 

        int maxLen = 0;
        int maxFreq = 0;
        int i = 0, j = 0;

        while (j < n) {
            char ch = s[j];

            freq[ch - 'A']++;
            maxFreq = max(maxFreq, freq[ch - 'A']);

            if ((j - i + 1) - maxFreq > k) {
                freq[s[i] - 'A']--;
                i++;
            }

            maxLen = max(maxLen, j - i + 1);

            j++;
        }

        return maxLen;
    }
};